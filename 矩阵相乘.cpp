#include <iostream>

#include <climits>
using namespace std;

void matrixMultiply(int **a, int **b, int **c, int ra, int ca, int rb, int cb) {
    if (ca != rb)
      cout<<"矩阵不可乘";
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


// 按最优次序进行矩阵乘法
void multiplyMatrices(int ***matrices, int **result, int i, int j, int **s, int *p) {
    if (i == j) {
        // 直接复制单个矩阵到结果
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

    multiplyMatrices(matrices, temp, i, s[i][j], s, p); // 左子链结果

    int **right = new int*[p[s[i][j]]];
    for (int k = 0; k < p[s[i][j]]; k++) {
        right[k] = new int[p[j]];
    }

    multiplyMatrices(matrices, right, s[i][j] + 1, j, s, p); // 右子链结果

    // 将左右子链的结果相乘
    matrixMultiply(temp, right, result, p[i - 1], p[s[i][j]], p[s[i][j]], p[j]);

    // 释放临时矩阵内存
    for (int k = 0; k < p[i - 1]; k++) delete[] temp[k];
    delete[] temp;
    for (int k = 0; k < p[s[i][j]]; k++) delete[] right[k];
    delete[] right;
}

int main() {
    int n;
    cout << "请输入矩阵的个数: ";
    cin >> n;

    // 动态分配内存
    int *p = new int[n + 1];  // 存储矩阵的维度
    int **m = new int*[n + 1];  // 动态分配 m 数组
    int **s = new int*[n + 1];  // 动态分配 s 数组

    for (int i = 0; i <= n; i++) {
        m[i] = new int[n + 1];
        s[i] = new int[n + 1];
    }

    // 输入每个矩阵的行和列
    cout << "输入每个矩阵的行和列: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "矩阵 " << i + 1 << " 的行数和列数: ";
        cin >> p[i] >> p[i + 1];
    }

    // 调用动态规划算法，计算最小标量乘法次数和最优分割点
    MatrixChain(p, n, m, s);

    // 输出最优计算次序
    cout << "最优计算次序为:" << endl;
    Traceback(1, n, s);  // 输出矩阵链乘法的最优计算次序
    cout << endl;

    // 输入矩阵的具体值
    int ***matrices = new int**[n + 1];
    for (int i = 1; i <= n; i++) {
        int rows = p[i - 1], cols = p[i];
        matrices[i] = new int*[rows];
        for (int x = 0; x < rows; x++) {
            matrices[i][x] = new int[cols];
            cout << "输入矩阵 " << i << " 的元素（" << rows << "x" << cols << "）：" << endl;
            for (int y = 0; y < cols; y++) {
                cin >> matrices[i][x][y];
            }
        }
    }

    // 按最优次序进行矩阵乘法
    int **result = new int*[p[0]];
    for (int i = 0; i < p[0]; i++) {
        result[i] = new int[p[n]];
    }

    multiplyMatrices(matrices, result, 1, n, s, p);

    // 输出最终结果矩阵
    cout << "最终结果矩阵：" << endl;
    for (int i = 0; i < p[0]; i++) {
        for (int j = 0; j < p[n]; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // 释放动态分配的内存
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