//https://acm.hdu.edu.cn/showproblem.php?pid=2021
//���٣�������ֵ���

#include <iostream>
using namespace std;

int money[6] = {100, 50, 10, 5, 2, 1};

// ĳ���˵Ĺ���������Ҫ����
int minmin(int amount) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        count += amount / money[i];
        amount %= money[i];
    }
    return count;
}

int main() {
    int n;  // ��������
    cin >> n;

    int salary[100] = {0};
    for (int i = 0; i < n; i++) {
        cin >> salary[i];
    }

    int totalCount = 0;
    for (int i = 0; i < n; i++) {
        totalCount += minmin(salary[i]);
    }

    cout << "������Ҫ��ֽ������: " << totalCount << endl;
    return 0;
}
