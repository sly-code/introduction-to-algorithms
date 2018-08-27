/*Description:n items. Item i is worth $v(i), weighs w(i) pounds.
Find a most valuable subset of items with total weight no more than W.
Have to either take an item or not take it-can't not take part of it.
Solution:define c(i,w) to be the solution for items 1,2,...,i and maximum
weight w. c(i,0)=c(0,w)=0
          c(i,w)=c(i-1,w) if w<w(i)
          c(i,w)=max{c(i-1,w),c(i-1,w-w(i))+v(i)} if w>=w(i)
Input:value array V[n]
      weight array W[n]
Output:items subset to take that maximizes payoff {i1,i2,...,i(k)}
*/
#include<iostream>
using namespace std;
int Zero_One_Knapsack(int V[],int W[],int n,int maxw){
    int C[n+1][maxw+1];
    int i,w;
    for(w=0;w<=maxw;w++) C[0][w]=0;
    for(i=1;i<=n;i++){
        C[i][0]=0;
        for(w=1;w<=maxw;w++){
            if(w<W[i-1]) C[i][w]=C[i-1][w];
            else C[i][w]=max(C[i-1][w],C[i-1][w-W[i-1]]+V[i-1]);
        }
    }
    i=n;w=maxw;
    while(i>0&&w>0){
        if(C[i][w]==C[i-1][w]) i--;
        else{
            cout<<i<<' ';
            w=w-W[i-1];
            i--;
        }
    }
    return C[n][maxw];
}
int main(){
    int n=3;
    int V[n]={60,100,120};
    int W[n]={10,20,30};
    cout<<endl<<Zero_One_Knapsack(V,W,n,0);
    return 0;
}
