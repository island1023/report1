//�Լ��ϻ���Ϊ��ͬ�ķǿ��Ӽ�
//���ϱ�����л�����
//���ϻ��־��ж�Ӧ�Ĺ�ʽ����Ҫ���õݹ�
//1 Ԫ�أ�1 �֣������Ӽ���
//2 Ԫ�أ�2 �֣�
//3 Ԫ�أ�5 ��
//4 Ԫ�أ�15 ��
//5 Ԫ�أ�52 �֣��ɼ������㣩
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
    cout<<"����Ԫ�ظ���";
    cin>>n;
    cout<<sum(n);
}
