#include<iostream>
using namespace std;
int maxsum(int n,int a[100],int &besti,int &bestj){
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int thissum=0;
            for(int k=i;k<=j;k++)  thissum+=a[k];
            if(thissum>sum){
                sum=thissum;
                besti=i;
                bestj=j;
            }
        }
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
    int besti,bestj=0;
    int k;
    k=maxsum(n,a,besti,bestj);
    cout<<"����ֶκͣ�"<<k;
    return 0;
}