//https://acm.hdu.edu.cn/showproblem.php?pid=2021
//最少：优先面值大的

#include <iostream>
using namespace std;

int money[6] = {100, 50, 10, 5, 2, 1};

// 某个人的工资最少需要多少
int minmin(int amount) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        count += amount / money[i];
        amount %= money[i];
    }
    return count;
}

int main() {
    int n;  // 工资人数
    cin >> n;

    int salary[100] = {0};
    for (int i = 0; i < n; i++) {
        cin >> salary[i];
    }

    int totalCount = 0;
    for (int i = 0; i < n; i++) {
        totalCount += minmin(salary[i]);
    }

    cout << "最少需要的纸币总数: " << totalCount << endl;
    return 0;
}
