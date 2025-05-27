//�����������˵ĳ�ʼ����Ϊ5�����������ƶ����ƶ��ٶ����1m/s
//����0~11�ķ�Χ����n���ڱ����ڱ��ڵ�T�����������x��������ͬʱ����
//����������ڱ������֮ǰ���˺��ڱ��������غ϶��ٴΣ�ͬһʱ��ͬһ���꣩

//�����ӽṹ���������귶ΧA(t+1)=A(t)+1��A(t)-1��A(t)  A(0)=5
//����ÿ��������tʱ�����ڱ�����

//�ݹ�ʽ   A(t+1)=A(t)+1��A(t)-1��A(t)  A(0)=5
// dp[A][t]=max(dp[A-1][t-1],dp[A][t-1],dp[A+1][t-1])+luo(A,t)

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000

// �Զ���������������ֵ�ĺ���
int max(int num1, int num2, int num3) {
    return max(num1, max(num2, num3));
}

// ͳ����ʱ�� t1 ����λ�� x1 ���ڱ�����
int luo(int x1, int t1, int X[], int T[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (X[i] == x1 && T[i] == t1) {
            count++;
        }
    }
    return count;
}

// ��̬�滮��������ڱ�����
int sum(int dp[11][MAX_N], int X[], int T[], int n) {
    int maxT = 0;
    // �ҳ�����ʱ�� T
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
        int n; // �ڱ�����
        cin >> n;
        int x[MAX_N], T[MAX_N];
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> T[i];
        }

        int dp[11][MAX_N] = {0};
        dp[5][0] = 0;

        int result = sum(dp, x, T, n);
        cout << "�ܽӵ�������ڱ�����: " << result << endl;
        return 0;
}




//��ȷ������ࣺ
 /*#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

// �Զ���������������ֵ�ĺ���
int max(int num1, int num2, int num3) {
    return std::max(num1, std::max(num2, num3));
}

// ͳ����ʱ�� t ����λ�� x ���ڱ�����
int luo(int x, int t, int X[], int T[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (X[i] == x && T[i] == t) {
            count++;
        }
    }
    return count;
}

// ��̬�滮��������ڱ�����
int sum(int dp[11][MAX_N], int X[], int T[], int n) {
    int maxT = 0;
    // �ҳ�����ʱ�� T
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
    int n; // �ڱ�����
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        int x[MAX_N], T[MAX_N];
        for (int i = 0; i < n; i++) {
            // ���ж�ȡ���� x, ����ʱ�� T
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