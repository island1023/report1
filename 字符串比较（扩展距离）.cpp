#include<iostream>
#include<string>
#include <cstdlib>
#include<algorithm>
using namespace std;
int jisuanlength(int n,int k,string &a,string &b){
    int sum=0;
    for(int i=0;i<n;i++){
        if((a[i]==' '&&b[i]!=' ')||(a[i]!=' '&&b[i]==' ')){
            sum+=k;
        }
      else { sum+=abs(static_cast<int>(a[i])-static_cast<int>(b[i]));}
    }
    return sum;
}

int space(int n, int k,string &a,string &b){
    int k1,k2,k3,ss=0;
    if(a.length()<n){
        int count1=n-a.length();
    }
    if(b.length()<n){
        int count2=n-a.length();
    }
    if(a.length()==n&&b.length()==n){
       k3=jisuanlength(n,k,a,b);
    }
    ss=max({k1,k2,k3});
    return ss;
}


//暴力解法

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

// 计算两个字符的 ASCII 值之差
int dist(char c1, char c2) {
    return abs(c1 - c2);
}

// 暴力求解函数
int bruteForce(string a, string b, int k, int i, int j) {
    // 如果 a 字符串已经遍历完，剩下的 b 字符串每个字符都需要删除
    if (i == a.length()) {
        return k * (b.length() - j);
    }
    // 如果 b 字符串已经遍历完，剩下的 a 字符串每个字符都需要删除
    if (j == b.length()) {
        return k * (a.length() - i);
    }

    // 情况 1: 匹配当前字符
    int match = bruteForce(a, b, k, i + 1, j + 1) + dist(a[i], b[j]);
    // 情况 2: 删除 a 中的当前字符
    int deleteA = bruteForce(a, b, k, i + 1, j) + k;
    // 情况 3: 删除 b 中的当前字符
    int deleteB = bruteForce(a, b, k, i, j + 1) + k;

    // 返回三种情况中的最小值
    return min(match, min(deleteA, deleteB));
}

int main() {
    string a, b;
    int k;
    cin >> a >> b >> k;

    // 调用暴力求解函数
    int result = bruteForce(a, b, k, 0, 0);
    cout << result << endl;

    return 0;
}