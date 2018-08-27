//Description:given matrices A1,A2,...,An
#include<iostream>
using namespace std;
const int INFINITY=INT_MAX;
const int N=6;
void Matrix_Chain_Order(int P[],int M[][N],int S[][N],int n){
    int i,j,k,l,temp;
    for(i=0;i<n;i++) M[i][i]=0;
    for(l=1;l<n;l++){
        for(i=0;i<n-l;i++){
            j=i+l;
            M[i][j]=INFINITY;
            for(k=i;k<j;k++){
                temp=M[i][k]+M[k+1][j]+P[i]*P[k+1]*P[j+1];
                if(temp<M[i][j]){M[i][j]=temp;S[i][j]=k;}
            }
        }
    }
}
void Print_Optimal_Parens(int S[][N],int i,int j){
    if(i==j){cout<<'A'<<i;}
    else{
        cout<<'(';
        Print_Optimal_Parens(S,i,S[i][j]);
        Print_Optimal_Parens(S,S[i][j]+1,j);
        cout<<')';
    }
}
int main(){
    int P[N+1]={30,35,15,5,10,20,25};
    int Q[N+1]={5,10,3,12,5,50,6};
    int M[N][N];
    int S[N][N];
    Matrix_Chain_Order(Q,M,S,N);
    Print_Optimal_Parens(S,0,N-1);
    cout<<endl<<"minimum multiplication="<<M[0][N-1];
    return 0;
}
