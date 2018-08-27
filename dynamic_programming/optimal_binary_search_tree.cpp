/*Description: given n different keywords in order K=(k1,k2,...,kn), k1<k2<...<kn, use these words to construct
a binary search tree. For each k(i), there is a probability p(i) indicating its search frequency. Some words to
be searched may be not in sequence K, so we have (n+1) pseudo-keywords d0,d1,d2,...,d(n) to represent words out of
K. d0 stands for all words smaller than k1 and d(n) all words bigger than kn. For each i=1,2,...,n-1, pseudo-keyword
d(i) stands for all words between k(i) and k(i+1). Again, for each d(i), it has a search frequency q(i).
Input:P[n]=search frequency array of keywords
      Q[n+1]=search frequency array of pseudo-keywords
Output:E[i][j]=expected search cost of optimal BST consisting of k(i),k(i+1),...,k(j)
       R[i][j]=root of corresponding BST
*/
#include<iostream>
#include<stdlib.h>
const int N=5;
using namespace std;
float Optimal_BST(float P[],float Q[],int R[][N],int n){
    int i,j,k,l;
    float temp;
    float **E=new float *[n+1];
    float **W=new float *[n+1];
    for(i=0;i<=n;i++){
        E[i]=new float[n+1];
        W[i]=new float[n+1];
        E[i][i]=W[i][i]=Q[i];
    }
    for(l=1;l<=n;l++){
        for(i=0;i<=n-l;i++){
            j=i+l;
            E[i][j]=INT_MAX;
            W[i][j]=W[i][j-1]+P[j-1]+Q[j];
            for(k=i+1;k<=j;k++){
                temp=E[i][k-1]+E[k][j]+W[i][j];
                if(temp<E[i][j]){
                    E[i][j]=temp;
                    R[i][j-1]=k;
                }
            }
        }
    }
    temp=E[0][n];
    for(i=0;i<=n;i++){
        delete[] E[i];
        delete[] W[i];
    }
    delete[] E;
    delete[] W;
    return temp;
}
int main(){
    int n=N;
    float P[n]={0.15,0.1,0.05,0.1,0.2};
    float Q[n+1]={0.05,0.10,0.05,0.05,0.05,0.1};
    int R[N][N];
    cout<<"minimum cost="<<Optimal_BST(P,Q,R,n)<<endl;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<'R'<<'['<<i+1<<','<<j+1<<']'<<'='<<R[i][j]<<endl;
        }
    }
    return 0;
    system("pause");
}
