#include<iostream>
using namespace std;
void LIS_1(int A[],int n){
    int L[n];//L[i]=length of LIS whose finial number is A[i]
    int S[n];//S[i]=subscript of the previous number of A[i] in the LIS that ends up with A[i]
    int i,j,k=0;
    int length=1;
    L[0]=1;S[0]=0;
    for(i=1;i<n;i++){
        L[i]=1;S[i]=i;
        for(j=i-1;j>=0;j--){
            if(A[i]>A[j]&&L[i]<L[j]+1){
                L[i]=L[j]+1;
                S[i]=j;
            }
        }
        if(length<L[i]){length=L[i];k=i;}//length=max{L[0],L[1],...,L[i]},k=corresponding subscript
    }
    cout<<A[k]<<' ';
    while(S[k]<k){
        k=S[k];cout<<A[k]<<' ';
    }
}
void LIS_2(int A[],int n){
    int B[n];//B[i] is index of the minimum final number of all increasing subsequence whose length is i+1
    int S[n];//S[i] is index of the precursor of A[i] as A[i] is the last number of some IS
    int i,low,high,mid,maxlength;
    B[0]=0;S[0]=0;maxlength=1;
    for(i=1;i<n;i++){
        B[i]=-1;
        low=0;high=i;//find the first number D[k] in {D[0],D[1],...,D[i]} that A[i]<=A[B[k]]
        while(low<high){
            mid=(low+high)/2;
            if(B[mid]==-1||A[i]<=A[B[mid]]) high=mid;
            else low=mid+1;
        }
        if(B[low]==-1) maxlength++;
        B[low]=i;S[i]=(low>0?B[low-1]:i);
    }
    i=B[maxlength-1];
    cout<<A[i]<<' ';
    while(S[i]<i){
        i=S[i];
        cout<<A[i]<<' ';
    }
}
int main(){
    int A[]={10,9,8,7,6,5,4,3,2,-1,-1,-2,-2,-2,-4,-7};
    LIS_1(A,11);
    cout<<endl;
    LIS_2(A,11);
    return 0;
}
