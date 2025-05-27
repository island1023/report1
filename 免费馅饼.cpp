//问题重述：人的初始坐标为5，可以左右移动，移动速度最大1m/s
//坐标0~11的范围掉落n个馅饼，馅饼在第T秒掉落在坐标x处，可以同时掉落
//求出在所有馅饼都落地之前，人和馅饼的坐标重合多少次（同一时间同一坐标）

//最优子结构分析：坐标范围A(t+1)=A(t)+1或A(t)-1或A(t)  A(0)=5
//饼：每个坐标在t时间有馅饼掉落

//递归式   A(t+1)=A(t)+1或A(t)-1或A(t)  A(0)=5
// dp[A][t]=max(dp[A-1][t-1],dp[A][t-1],dp[A+1][t-1])+luo(A,t)

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000

// 自定义的求三个数最大值的函数
int max(int num1, int num2, int num3) {
    return max(num1, max(num2, num3));
}

// 统计在时间 t1 落在位置 x1 的馅饼数量
int luo(int x1, int t1, int X[], int T[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (X[i] == x1 && T[i] == t1) {
            count++;
        }
    }
    return count;
}

// 动态规划计算最大馅饼数量
int sum(int dp[11][MAX_N], int X[], int T[], int n) {
    int maxT = 0;
    // 找出最大的时间 T
    for (int i = 0; i < n; i++) {
        if (T[i] > maxT) {
            maxT = T[i];
        }
    }

    for (int t = 1; t <= maxT; t++) {
        for (int A = 0; A <= 10; A++) {
            int prev1 = (A - 1 >= 0) ? dp[A - 1][t - 1] : 0;
            int prev2 = dp[A][t - 1];
            int prev3 = (A + 1 <= 10) ? dp[A + 1][t - 1] : 0;
            dp[A][t] = max(prev1, prev2, prev3) + luo(A, t, X, T, n);
        }
    }

    int ans = 0;
    for (int A = 0; A <= 10; A++) {
        ans = max(ans, dp[A][maxT]);
    }
    return ans;
}

int main() {
        int n; // 馅饼个数
        cin >> n;
        int x[MAX_N], T[MAX_N];
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> T[i];
        }

        int dp[11][MAX_N] = {0};
        dp[5][0] = 0;

        int result = sum(dp, x, T, n);
        cout << "能接到的最大馅饼数是: " << result << endl;
        return 0;
}




//正确个数最多：
 /*#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

// 自定义的求三个数最大值的函数
int max(int num1, int num2, int num3) {
    return std::max(num1, std::max(num2, num3));
}

// 统计在时间 t 落在位置 x 的馅饼数量
int luo(int x, int t, int X[], int T[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (X[i] == x && T[i] == t) {
            count++;
        }
    }
    return count;
}

// 动态规划计算最大馅饼数量
int sum(int dp[11][MAX_N], int X[], int T[], int n) {
    int maxT = 0;
    // 找出最大的时间 T
    for (int i = 0; i < n; i++) {
        if (T[i] > maxT) {
            maxT = T[i];
        }
    }
for (int t = 1; t <= maxT; t++) {
        for (int A = 0; A <= 10; A++) {
            int prev1 = (A - 1 >= 0 && dp[A - 1][t - 1] != -MAX_N) ? dp[A - 1][t - 1] : -MAX_N;
            int prev2 = dp[A][t - 1] != -MAX_N ? dp[A][t - 1] : -MAX_N;
            int prev3 = (A + 1 <= 10 && dp[A + 1][t - 1] != -MAX_N) ? dp[A + 1][t - 1] : -MAX_N;
            dp[A][t] = max(prev1, prev2, prev3) + luo(A, t, X, T, n);
        }
    }

    int ans = 0;
    for (int A = 0; A <= 10; A++) {
        if (dp[A][maxT] != -MAX_N) {
            ans = std::max(ans, dp[A][maxT]);
        }
    }
    return ans;
}
int main() {
    int n; // 馅饼个数
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        int x[MAX_N], T[MAX_N];
        for (int i = 0; i < n; i++) {
            // 逐行读取坐标 x, 掉落时间 T
            scanf("%d %d", &x[i], &T[i]);
        }
        int dp[11][MAX_N];
        for (int i = 0; i <= 10; i++) {
            for (int j = 0; j < MAX_N; j++) {
                dp[i][j] = -MAX_N;
            }
        }
        dp[5][0] = 0;

        int result = sum(dp, x, T, n);
        printf("%d\n", result);
    }
    return 0;
}*/