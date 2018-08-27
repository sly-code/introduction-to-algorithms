//Input:X=(x0,x1,...,x(m-1)),Y=(y0,y1,...,y(n-1))
//Output:LCS of X and Y
#include <iostream>
#include<string>
using namespace std;
void LCS(const string &X,const string &Y){
    int m=X.length();
    int n=Y.length();
    int i,j,k;
    int **A=new int *[m+1];
    for(i=0;i<=m;i++) A[i]=new int[n+1];
    for(i=0;i<=m;i++) A[i][0]=0;
    for(j=0;j<=n;j++) A[0][j]=0;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(X[i-1]==Y[j-1]) A[i][j]=A[i-1][j-1]+1;
            else if(A[i-1][j]>A[i][j-1]) A[i][j]=A[i-1][j];
            else A[i][j]=A[i][j-1];
        }
    }
    k=A[m][n];i=m;j=n;
    string s(k,'$');
    while(i>0&&j>0){
        if(X[i-1]==Y[j-1]){s[k-1]=X[i-1];k--;i--;j--;}
        else if(A[i][j]==A[i-1][j]){i--;}
        else j--;
    }
    cout<<s<<endl;
    for(i=0;i<=m;i++) delete[] A[i];
    delete[] A;
}
int main(){
    string s1="babfgh";
    string s2="abcdefg";
    LCS(s1,s2);
    return 0;
}
