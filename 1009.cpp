//https://acm.hdu.edu.cn/showproblem.php?pid=1009
//胖老鼠准备了 M 磅猫粮，去和守卫仓库的猫咪们交易，换取JavaBean（咖啡豆）。
//这个仓库一共有 N 个房间。
//第 i 个房间里有 J[i] 磅 JavaBean，但要想进入这个房间，就必须支付 F[i] 磅猫粮。
///支付 F[i] × a 磅猫粮，就能获得 J[i] × a 磅 JavaBean。
//在给定 M 磅猫粮的前提下，胖老鼠最多能获得多少磅 JavaBean
//第一行包含两个非负整数 M 和 N。
//接下来有 N 行，每行包含两个非负整数 J[i] 和 F[i]，
// 分别表示第 i 个房间中的 JavaBean 数量和所需的猫粮数量。
//当遇到一行两个 -1 时，表示输入结束。
//所有整数均不大于 1000
//计算p=j[i]/f[i],优先选择p大的

#include <iostream>
using namespace std;

// 排序函数：按p降序，同时同步交换j和f
void sort_desc(int j[], int f[], double p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int k = 0; k < n - 1 - i; k++) {
            if (p[k] < p[k + 1]) {
                // 交换p
                double temp_p = p[k];
                p[k] = p[k + 1];
                p[k + 1] = temp_p;
                // 交换j
                int temp_j = j[k];
                j[k] = j[k + 1];
                j[k + 1] = temp_j;
                // 交换f
                int temp_f = f[k];
                f[k] = f[k + 1];
                f[k + 1] = temp_f;
            }
        }
    }
}

// 计算每个房间的p值
void calc_p(int j[], int f[], double p[], int n) {
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) p[i] = 0.0; // 避免除零
        else p[i] = (double)j[i] / f[i];
    }
}

// 计算最大可获得JavaBeans总数
double calc_max_bean(int M, int j[], int f[], double p[], int n) {
    sort_desc(j, f, p, n);

    double result = 0.0;
    int remain = M;

    for (int i = 0; i < n; i++) {
        if (remain == 0) break;
        if (f[i] <= remain) {
            result += j[i];
            remain -= f[i];
        } else {
            double fraction = (double)remain / f[i];
            result += j[i] * fraction;
            remain = 0;
        }
    }
    return result;
}

int main() {
    while (true) {
        int M, N;
        cin >> M >> N;
        if (M == -1 && N == -1) break;

        int j[100], f[100];
        double p[100];

        for (int i = 0; i < N; i++) {
            cin >> j[i] >> f[i];
        }

        calc_p(j, f, p, N);
        double ans = calc_max_bean(M, j, f, p, N);
        printf("%.3f\n", ans);
    }
    return 0;
}
