//给定方程 8*x^4 + 7*x^3 + 2*x^2 + 3*x + 6 == Y，
// 在 0 到 100 之间找到它的解
//输入的第一行包含一个整数 T（1<=T<=100），表示测试用例的数量。
// 然后 T 行紧随其后，每行都有一个实数 Y （fabs（Y） <= 1e10）;
//对于每个测试用例，您应该只输出一个实数（精确到小数点后 4 位）
// 这是方程的解，如果 0 到 100 之间的方程没有解，则输出 “No solution！”。

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double trytry(int a) {
    for (double i = 0; i <= 100; i += 0.0001) { // 以更小步长搜索
        double temp = 8 * pow(i, 4) + 7 * pow(i, 3) + 2 * pow(i, 2) + 3 * i + 6;
        if (fabs(temp - a) < 1e-6) { // 浮点数比较
            return i;
        }
    }
    return -1; // 无解
}

void solve(int in[], int t) {
    for (int i = 0; i < t; i++) {
        double l = trytry(in[i]);
        if (l != -1) {
            cout << fixed << setprecision(4) << l << endl;
        } else {
            cout << "No solution!" << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    int in[100];
    for (int i = 0; i < t; i++) {
        cin >> in[i];
    }
    solve(in, t);
    return 0;
}

//样本输入
//2
//100
//-4

//示例输出
//1.6152
//No solution!