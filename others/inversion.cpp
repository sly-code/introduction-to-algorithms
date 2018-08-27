#include<iostream>
typedef int ElemType;
int Merge_Inversion(ElemType A[],size_t p,size_t q,size_t r){//merge the sorted sub-array A[p,q] and A[q+1,r] into A[p,r]
    ElemType *L=new ElemType[q-p+1];
    ElemType *R=new ElemType[r-q];
    size_t i,j,k;
    for(i=0;i<q-p+1;i++) L[i]=A[p+i];
    for(j=0;j<r-q;j++) R[j]=A[q+j+1];
    int ret=0;
    for(i=0,j=0,k=p;i<q-p+1&&j<r-q;k++){
        if(L[i]<=R[j]){A[k]=L[i];i++;}
        else {A[k]=R[j];j++;ret+=q-p+1-i;}
    }
    if(i==q-p+1)
        for(;j<r-q;j++,k++) A[k]=R[j];
    else
        for(;i<q-p+1;i++,k++) A[k]=L[i];
    delete[] L;
    delete[] R;
    std::cout<<p<<' '<<q<<' '<<r<<' '<<ret<<std::endl;
    return ret;
}

int Count_Inversion(ElemType A[],size_t p,size_t r){//sort sub-array A[p,r] using recursion
    int inver=0;
    if(p<r){
       size_t q=(p+r)/2;
       inver+=Count_Inversion(A,p,q);
       inver+=Count_Inversion(A,q+1,r);
       inver+=Merge_Inversion(A,p,q,r);
    }
    return inver;
}
int main(){
    ElemType A[]={-1,2,9,7,0,1,3,6};
    std::cout<<Count_Inversion(A,0,7)<<std::endl;
}
