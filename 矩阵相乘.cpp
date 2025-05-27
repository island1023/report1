#include <iostream>

#include <climits>
using namespace std;

void matrixMultiply(int **a, int **b, int **c, int ra, int ca, int rb, int cb) {
    if (ca != rb)
      cout<<"���󲻿ɳ�";
    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            int sum = a[i][0] * b[0][j];
            for (int k = 1; k < ca; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }
}

void MatrixChain(int *p, int n, int **m, int **s) {
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int r = 2; r <= n; r++) {
        for (int i = 1; i <= n - r + 1; i++) {
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; k++) {
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void Traceback(int i, int j, int **s) {
    if (i == j)
        return;
    Traceback(i, s[i][j], s);
    Traceback(s[i][j] + 1, j, s);
    cout << "Multiply A " << i << ", " << s[i][j];
    cout << " and A " << (s[i][j] + 1) << ", " << j << endl;
}


// �����Ŵ�����о���˷�
void multiplyMatrices(int ***matrices, int **result, int i, int j, int **s, int *p) {
    if (i == j) {
        // ֱ�Ӹ��Ƶ������󵽽��
        for (int x = 0; x < p[i - 1]; x++) {
            for (int y = 0; y < p[i]; y++) {
                result[x][y] = matrices[i][x][y];
            }
        }
        return;
    }

    int **temp = new int*[p[i - 1]];
    for (int k = 0; k < p[i - 1]; k++) {
        temp[k] = new int[p[s[i][j]]];
    }

    multiplyMatrices(matrices, temp, i, s[i][j], s, p); // ���������

    int **right = new int*[p[s[i][j]]];
    for (int k = 0; k < p[s[i][j]]; k++) {
        right[k] = new int[p[j]];
    }

    multiplyMatrices(matrices, right, s[i][j] + 1, j, s, p); // ���������

    // �����������Ľ�����
    matrixMultiply(temp, right, result, p[i - 1], p[s[i][j]], p[s[i][j]], p[j]);

    // �ͷ���ʱ�����ڴ�
    for (int k = 0; k < p[i - 1]; k++) delete[] temp[k];
    delete[] temp;
    for (int k = 0; k < p[s[i][j]]; k++) delete[] right[k];
    delete[] right;
}

int main() {
    int n;
    cout << "���������ĸ���: ";
    cin >> n;

    // ��̬�����ڴ�
    int *p = new int[n + 1];  // �洢�����ά��
    int **m = new int*[n + 1];  // ��̬���� m ����
    int **s = new int*[n + 1];  // ��̬���� s ����

    for (int i = 0; i <= n; i++) {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }

    // ����ÿ��������к���
    cout << "����ÿ��������к���: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "���� " << i + 1 << " ������������: ";
        cin >> p[i] >> p[i + 1];
    }

    // ���ö�̬�滮�㷨��������С�����˷����������ŷָ��
    MatrixChain(p, n, m, s);

    // ������ż������
    cout << "���ż������Ϊ:" << endl;
    Traceback(1, n, s);  // ����������˷������ż������
    cout << endl;

    // �������ľ���ֵ
    int ***matrices = new int**[n + 1];
    for (int i = 1; i <= n; i++) {
        int rows = p[i - 1], cols = p[i];
        matrices[i] = new int*[rows];
        for (int x = 0; x < rows; x++) {
            matrices[i][x] = new int[cols];
            cout << "������� " << i << " ��Ԫ�أ�" << rows << "x" << cols << "����" << endl;
            for (int y = 0; y < cols; y++) {
                cin >> matrices[i][x][y];
            }
        }
    }

    // �����Ŵ�����о���˷�
    int **result = new int*[p[0]];
    for (int i = 0; i < p[0]; i++) {
        result[i] = new int[p[n]];
    }

    multiplyMatrices(matrices, result, 1, n, s, p);

    // ������ս������
    cout << "���ս������" << endl;
    for (int i = 0; i < p[0]; i++) {
        for (int j = 0; j < p[n]; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // �ͷŶ�̬������ڴ�
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x < p[i - 1]; x++) delete[] matrices[i][x];
        delete[] matrices[i];
    }
    delete[] matrices;

    for (int i = 0; i < p[0]; i++) delete[] result[i];
    delete[] result;

    for (int i = 0; i <= n; i++) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
    delete[] p;

    return 0;
}