//集合含有n个元素，可能存在重复元素，列出集合的所有不同排列
//输入：input.txt
//第一行：n
//第二行是待排列的n个元素   aacc
//输出：output.txt

#include<iostream>
#include<string>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int get(char b[], int xx[], int n, string c);
long factorial(int n);
int count(int xx[], int n);
void issort(char b[], int xx[], int n);

int get(char b[], int xx[], int n, string c) {
    int ct = 0;
    // 找到不同字符及其出现次数
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < ct; j++) {
            if (c[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            b[ct++] = c[i];
        }
    }
    // 计算每个字符的出现次数
    for (int i = 0; i < ct; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i] == c[j]) {
                xx[i]++;
            }
        }
    }
    return ct;
}


long factorial(int n) {
    long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int count(int xx[], int n) {
    // 计算所有字符的排列数，即 n!
    long sum = factorial(n);
    // 除以每个字符出现次数的阶乘
    for (int i = 0; i < 100; i++) {
        if (xx[i] > 1) {
            sum /= factorial(xx[i]);
        }
    }
    return sum;
}




void issort(char b[], int xx[], int n) {
    string s = "";
    // 根据字符出现次数构建字符串
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < xx[i]; j++) {
            s += b[i];
        }
    }
    sort(s.begin(), s.end());  // 排序以生成标准排列
    set<string> unique_permutations;
    do {
        unique_permutations.insert(s);  // 使用 set 去重
    } while (next_permutation(s.begin(), s.end()));

    // 输出每个唯一排列
    for (const auto& perm : unique_permutations) {
        cout << perm << " ";
    }
}



int main() {
    ifstream inFile("C:\\Users\\xy\\Desktop\\input.txt");
    if (!inFile.is_open()) {
        cout << "输入失败";
        return 1;
    }

    int n;
    string c;
    inFile >> n >> c;
    inFile.close();

    char b[100];
    for (int i = 0; i < 100; i++) {
        b[i] = '\0';
    }
    int xx[100] = {0};
    int ct = get(b, xx, n, c);
    int sum = count(xx, n);  // 修改为传递n
    cout << "输出如下" << endl;
    cout << "不同排列个数: " << sum << endl;
    issort(b, xx, n);
    return 0;
}
