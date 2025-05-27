/*
#include <iostream>
#include <string>
using namespace std;

const int MAXSIZE = 100; // �����������100����

// ����
template <class Type>
void Swap(Type& a, Type& b) {
    Type temp = a;
    a = b;
    b = temp;
}

// ����
template <class Type>
int Partition(Type a[], int p, int r) {
    int i = p, j = r + 1;
    Type x = a[p];
    while (true) {
        while (a[++i] < x && i < r);
        while (a[--j] > x);
        if (i >= j) break;
        Swap(a[i], a[j]);
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}

// ��������
template <class Type>
void QuickSort(Type a[], int p, int r) {
    if (p < r) {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);  // �����
        QuickSort(a, q + 1, r);  // ���ұ�
    }
}

int main() {
    int arr[MAXSIZE];
    int n = 0;
    string input;

    // �������ݣ�ֱ������ a
    while (cin >> input && input != "a" && input != "A") {
        arr[n++] = stoi(input);  // ��������ַ���תΪ������������
    }

    QuickSort(arr, 0, n - 1);   // ���ź�������

    // ���������
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

*/

#include <iostream>
using namespace std;

// ��������
template <class type>
void myswap(type &a, type &b) {
    type temp = a;
    a = b;
    b = temp;
}

// ��������
template <class type>
int partition(type c[], int p, int r) {
    int i = p, j = r + 1;
    type x = c[p];
    while (true) {
        while (i < r && c[++i] < x); // i����С��r������Խ��
        while (c[--j] > x);          // j���Ե���p����������
        if (i >= j) break;           // i��j��������
        myswap(c[i], c[j]);            // �������ҵ���
    }
    myswap(c[p], c[j]);                // �ؼ��㣺��׼ֵx�ŵ���ȷλ��
    return j;                        // ����x����λ��
}

// ���ŵݹ�
template <class type>
void QuickSort(type a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}

int main() {
    int a[100] = {0};
    int n = 0;
    while (n < 100) {            // ������for����while
        string input;
        cin >> input;
        if (input == "a") break; // �ж��ַ��� "a" ��ʾֹͣ����
        a[n] = stoi(input);      // �ַ���ת����
        n++;
    }

    QuickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
