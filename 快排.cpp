/*
#include <iostream>
#include <string>
using namespace std;

const int MAXSIZE = 100; // 假设最多输入100个数

// 交换
template <class Type>
void Swap(Type& a, Type& b) {
    Type temp = a;
    a = b;
    b = temp;
}

// 分区
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

// 快速排序
template <class Type>
void QuickSort(Type a[], int p, int r) {
    if (p < r) {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);  // 排左边
        QuickSort(a, q + 1, r);  // 排右边
    }
}

int main() {
    int arr[MAXSIZE];
    int n = 0;
    string input;

    // 输入数据，直到输入 a
    while (cin >> input && input != "a" && input != "A") {
        arr[n++] = stoi(input);  // 把输入的字符串转为整数放入数组
    }

    QuickSort(arr, 0, n - 1);   // 快排函数调用

    // 输出排序结果
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

*/

#include <iostream>
using namespace std;

// 交换函数
template <class type>
void myswap(type &a, type &b) {
    type temp = a;
    a = b;
    b = temp;
}

// 分区函数
template <class type>
int partition(type c[], int p, int r) {
    int i = p, j = r + 1;
    type x = c[p];
    while (true) {
        while (i < r && c[++i] < x); // i必须小于r，避免越界
        while (c[--j] > x);          // j可以等于p，不用限制
        if (i >= j) break;           // i与j交错，结束
        myswap(c[i], c[j]);            // 交换左右的数
    }
    myswap(c[p], c[j]);                // 关键点：基准值x放到正确位置
    return j;                        // 返回x最终位置
}

// 快排递归
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
    while (n < 100) {            // 不建议for，改while
        string input;
        cin >> input;
        if (input == "a") break; // 判断字符串 "a" 表示停止输入
        a[n] = stoi(input);      // 字符串转整数
        n++;
    }

    QuickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
