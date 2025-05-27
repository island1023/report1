#include<iostream>
using namespace std;
int maxsum(int n,int a[100]){
    int sum=0,b=0;
    for(int i=1;i<=n;i++){
        if(b>0) b+=a[i];
        else b=a[i];
        if(b>sum) sum=b;
    }
    return sum;
}
int main(){
    cout<<"输入个数：";
    int n;
    cin>>n;
    cout<<"输入各个整数：";
    int a[100]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=maxsum(n,a);
    cout<<"最大字段和："<<k;
    return 0;
}