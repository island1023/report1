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
    cout<<"���������";
    int n;
    cin>>n;
    cout<<"�������������";
    int a[100]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=maxsum(n,a);
    cout<<"����ֶκͣ�"<<k;
    return 0;
}