/*Description:c(i,j)=length of LPS of string {a(i),a(i+1),...,a(j)
     c(i,i-1)=0
     c(i,i)=1
     c(i,j)=c(i+1,j-1)+2, j>i if a(i)=a(j)
     c(i,j)=max{c(i+1,j),c(i,j-1)} j>i else.
Input:string S={a(0),a(1),...,a(n-1)}
Output: print LPS of s
*/
#include<iostream>
using namespace std;
int LPS(const string &S){
    int n=S.length();
    int i,j;
    int **C=new int *[n];
    for(i=0;i<n;i++){
        C[i]=new int[n];
        C[i][i]=1;
    }
    for(i=1;i<n;i++) C[i][i-1]=0;
    for(j=1;j<n;j++){
        for(i=j-1;i>=0;i--){
            if(S[i]==S[j]) C[i][j]=C[i+1][j-1]+2;
            else C[i][j]=(C[i+1][j]>C[i][j-1]?C[i+1][j]:C[i][j-1]);
        }
    }
    int maxlength=C[0][n-1];
    i=0;j=n-1;
    string lps(maxlength,'$');
    n=0;
    while(i<=j){
        if(S[i]==S[j]){lps[n]=lps[maxlength-1-n]=S[i];i++;j--;n++;}
        else if(C[i+1][j]>C[i][j-1]) i++;
        else j--;
    }
    cout<<lps;
    for(i=0;i<n;i++) delete[] C[i];
    delete[] C;
    return maxlength;
}
int main(){
    string s="cccaccc";
    cout<<LPS(s);
    return 0;
}
