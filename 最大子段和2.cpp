#include<iostream>
using namespace std;
int maxsubsum(int a[100],int left,int right){
    int sum=0;
    if(left==right){
        sum=a[left]>0?a[left]:0;
    }
    else{
        int center=(left+right)/2;
        int leftsum=maxsubsum(a,left,center);
        int rightsum=maxsubsum(a,center+1,right);
        int s1=0;
        int lefts=0;
        for(int i=center;i>=left;i--){
            lefts+=a[i];
            if(lefts>s1) s1=lefts;
        }
        int s2=0;
        int rights=0;
        for(int i=center+1;i<=right;i++){
            rights+=a[i];
            if(rights>s2) s2=rights;
        }
        sum=s1+s2;
        if(sum<leftsum) sum=leftsum;
        if(sum<rightsum) sum=rightsum;
    }
    return sum;
}
int maxsum(int n,int a[100]){
    return maxsubsum(a,1,n);
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