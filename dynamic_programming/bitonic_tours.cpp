/*Description:
Input:point array P[n][2]
Output:edge sequences {(i,j)}
*/
#include<iostream>
#include<cmath>
using namespace std;
float Bitonic_Tours(int P[][2],int n){
    //sort points into increasing order by x-coordinate P[i][0]
    int i,j,x,y;
    for(j=1;j<n;j++){
        x=P[j][0];y=P[j][1];
        for(i=j-1;i>=0&&P[i][0]>x;i--){
            P[i+1][0]=P[i][0];P[i+1][1]=P[i][1];
        }
        P[i+1][0]=x;P[i+1][1]=y;
    }
    //compute distance between point i and point j
    float **D=new float*[n-1];
    for(i=0;i<n-1;i++){
        D[i]=new float[n-1];
        for(j=i+1;j<n;j++)
            D[i][j-1]=sqrt((P[i][0]-P[j][0])*(P[i][0]-P[j][0])+(P[i][1]-P[j][1])*(P[i][1]-P[j][1]));
    }
    //compute length of shortest bi-tonic path c(i,j) that starts from p(i), goes right to p(n-1),
    //and then goes left to return to p(j)
    float **C=new float *[n-1];
    for(i=0;i<n-1;i++){
        C[i]=new float[n-1];
        C[i][n-2]=D[i][n-2];
    }
    for(j=n-2;j>=0;j--){
        for(i=j-1;i>=0;i--)
        C[i][j-1]=min(C[j][j]+D[i][j],C[i][j]+D[j][j]);
    }
    //use c[i][j] to reconstruct the shortest path
    i=0;j=1;
    cout<<'('<<i<<','<<j<<')'<<endl;
    while(j<n-1){
        if(fabs(C[i][j-1]-C[j][j]-D[i][j])<fabs(C[i][j-1]-C[i][j]-D[j][j])){
            cout<<'('<<i<<','<<j+1<<')'<<endl;
            i=j;
        }
        else cout<<'('<<j<<','<<j+1<<')'<<endl;
        j++;
    }
    cout<<'('<<i<<','<<j<<')'<<endl;
    float length=C[0][0]+D[0][0];
    for(i=0;i<n-1;i++){
        delete[] C[i];
        delete[] D[i];
    }
    delete[] C;
    delete[] D;
    return length;
}
int main(){
    int n=7;
    int P[n][2]={3,0,1,1,6,2,2,0,3,0,1,0,8,0};
    cout<<Bitonic_Tours(P,7);
    return 0;
}
