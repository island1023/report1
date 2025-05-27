//时间复杂度 O(k*(n^3))

/*
 #include <iostream>
using namespace std;

const long long MOD = 1000000007;

// 矩阵乘法 (mod 1000000007)
void multi(int a[100][100], int b[100][100], int n) {
    long long temp[100][100] = {0}; // 存储中间结果

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] = (temp[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    // 将 temp 赋值回 a
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = temp[i][j];
        }
    }
}

// 矩阵快速幂 a^k
void power(int a[100][100], int k, int n) {
    int res[100][100] = {0}; // 结果矩阵
    int base[100][100];      // 复制 a 到 base，防止修改原矩阵

    // 初始化 res 为单位矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = (i == j) ? 1 : 0;
            base[i][j] = a[i][j];
        }
    }

    // 矩阵快速幂
    while (k > 0) {
        if (k % 2 == 1) {  // k 为奇数，乘 base
            multi(res, base, n);
        }
        multi(base, base, n);  // base *= base
        k /= 2;
    }

    // 结果复制回 a
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = res[i][j];
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int a[100][100];

    // 输入矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    power(a, k, n); // 计算 a^k

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

*/


//快速矩阵幂的优化写法。O(logk*(n^3))
#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 100; // 矩阵大小上限

// 矩阵乘法
void multiply(int A[MAXN][MAXN], int B[MAXN][MAXN], int n) {
    long long temp[MAXN][MAXN] = {0}; // 结果矩阵

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                temp[i][j] = (temp[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    // 复制结果回 A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = temp[i][j];
        }
    }
}

// 快速矩阵幂计算 A^k
void matrixPower(int A[MAXN][MAXN], int k, int n) {
    int result[MAXN][MAXN] = {0}; // 单位矩阵

    // 初始化单位矩阵
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }

    while (k > 0) {
        if (k & 1) { // 如果 k 的当前二进制位是 1
            multiply(result, A, n);
        }
        multiply(A, A, n); // A = A * A
        k >>= 1; // k 右移，相当于 k //= 2
    }

    // 复制 result 回 A，使得 A 变成 A^k
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = result[i][j];
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int A[MAXN][MAXN];

    // 输入矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    matrixPower(A, k, n); // 计算 A^k

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
