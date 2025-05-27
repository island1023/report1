//对集合划分为不同的非空子集
//集合本身具有互异性
//集合划分具有对应的公式，需要采用递归
//1 元素：1 种（单个子集）
//2 元素：2 种（
//3 元素：5 种
//4 元素：15 种
//5 元素：52 种（可继续计算）
//S(n,k)=k*S(n-1,k)+S(n-1,k-1)
//S(0,0)=1,S(n,0)=0(n>0),S(0,k)=0(k>0)

#include<iostream>
using namespace std;
int ss(int n,int k){
    if(n==0&&k==0) return 1;
    if((n==0&&k!=0)||(n!=0&&k==0)) return 0;
    if(n==k) return 1;
    return k*ss(n-1,k)+ss(n-1,k-1);
}
int  sum(int n){
     int sum=0;
     for(int k=1;k<=n;k++){
         sum+=ss(n,k);
     }
     return sum;
}
int main(){
    int n;
    cout<<"输入元素个数";
    cin>>n;
    cout<<sum(n);
}
