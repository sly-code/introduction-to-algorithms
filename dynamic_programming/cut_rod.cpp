//Input:price array P[n]
//Output: max payoff array R[n] and first cut length array S[n]
#include<iostream>
const int INFINITY=INT_MAX;
using namespace std;
void Cut_Rod(int P[],int R[],int S[], int n){
    R[0]=0;
    int i,j;int temp;
    for(j=1;j<=n;j++){//compute R[j] and S[j]
        temp=-INFINITY;
        for(i=1;i<=j;i++){
            if(temp<P[i]+R[j-i]){temp=P[i]+R[j-i];S[j]=i;}
        }
        R[j]=temp;
    }
}
int main(){
    int n=10;
    int P[]={0,1,5,8,9,10,17,17,20,24,30};
    int R[n+1],S[n+1];
    Cut_Rod(P,R,S,n);
    for(int i=1;i<=n;i++){
        cout<<i<<' '<<R[i]<<' '<<S[i]<<endl;
    }
    return 0;
}
