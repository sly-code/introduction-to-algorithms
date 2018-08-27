#include "sort.h"
#include<stack>
template<class ElemType>
void InsertSort(ElemType A[],size_t n){//best: theta(n), average: theta(n^2), worst: theta(n^2)
    size_t i,j;ElemType key;
    for(i=1;i<n;i++){
        key=A[i];
        for(j=i;j>0&&key<A[j-1];j--)
            A[j]=A[j-1];
        A[j]=key;
    }
}

template<class ElemType>
void SelectSort(ElemType A[],size_t n){//time complexity: theta(n^2) for all cases
    size_t i,j,k;ElemType key;
    for(i=0;i<n-1;i++){//search for the minimum value among A[i],A[i+1],...,A[n-1]
        k=i;//k is the index of the smallest element in A[i..n-1]
        for(j=i+1;j<n;j++){
            if(A[j]<A[k]) k=j;
        }
        key = A[k];
        A[k]=A[i];
        A[i]=key;
    }
}

template<class ElemType>
void ArrayMerge(ElemType A[],size_t p,size_t q,size_t r){//merge the sorted sub-array A[p,q] and A[q+1,r] into A[p,r]
    ElemType *L=new ElemType[q-p+1];
    ElemType *R=new ElemType[r-q];
    size_t i,j,k;
    for(i=0;i<q-p+1;i++) L[i]=A[p+i];
    for(j=0;j<r-q;j++) R[j]=A[q+j+1];
    for(i=0,j=0,k=p;i<q-p+1&&j<r-q;k++){
        if(L[i]<=R[j]){A[k]=L[i];i++;}
        else {A[k]=R[j];j++;}
    }
    if(i==q-p+1)
        for(;j<r-q;j++,k++) A[k]=R[j];
    else
        for(;i<q-p+1;i++,k++) A[k]=L[i];
    delete[] L;
    delete[] R;
}

template<class ElemType>
void MergeSort(ElemType A[],size_t p,size_t r){//recursive version of merge sort. time complexity: theta(nlogn£©for all cases
    if(p<r){
       size_t q=(p+r)/2;
       MergeSort(A,p,q);
       MergeSort(A,q+1,r);
       ArrayMerge(A,p,q,r);
    }
}

template<class ElemType>
void MergeSort(ElemType A[],size_t n){//non-recursive version merge sort
    if(n<=1) return;
    std::stack<std::pair<size_t, size_t> > S;
    size_t prev = n;
    size_t p=0, r=n-1,q;
    while(1){
        while(p<r){S.push(std::make_pair(p,r));r=(p+r)/2;}
        p=S.top().first; r=S.top().second;q=(p+r)/2;
        while(r==p+1 || r==p+2 || prev==q+1){
            ArrayMerge(A,p,q,r);
            prev=p;S.pop();
            if(S.empty()) return;
            p=S.top().first; r=S.top().second;q=(p+r)/2;
        }
        p=(p+r)/2+1;
    }
}

template<class ElemType>
size_t Partition(ElemType A[],size_t p,size_t r){//partition A[p,r] into A[p,q-1] and A[q+1,r] and return q
    size_t i=p;ElemType e;
    for(size_t j=p;j<=r;j++){//A[p,i]<=A[r], A[i+1,j-1]>A[r], j: the next element to be considered
        if(A[j]<=A[r]){
            e=A[i];A[i]=A[j];A[j]=e;
            i++;
        }
    }
    return i-1;
}

template<class ElemType>
void QuickSort(ElemType A[],size_t p,size_t r){
    size_t q;
    while(p<r){
        q=Partition(A,p,r);
        if(q-p<r-q){
            if(q>p+1) QuickSort(A,p,q-1);
            p=q+1;
        }
        else{
            QuickSort(A,q+1,r);
            r=q-1;
        }
    }
}

void CountSort(unsigned A[],unsigned N){//input of the function: array A[0,N-1]
    unsigned *B=new unsigned[N];
    unsigned *C=new unsigned[0x7fff]();
    unsigned i=0;
    for(i=0;i<N;i++) C[A[i]]++;
    for(i=1;i<=0x7fff;i++) C[i]=C[i]+C[i-1];
    for(i=0;i<N;i++){B[C[A[i]]-1]=A[i];C[A[i]]--;}
    for(i=0;i<N;i++) A[i]=B[i];
    delete[] B;
    delete[] C;
}
template<class ElemType>
void Heapify(ElemType A[], size_t heapsize, size_t i){//assume both the left subtree and right subtree of node i are already max heaps
    size_t lchild,rchild,largest;                     //time complexity O(h)
    ElemType e;
    while(i<heapsize/2){
        lchild=2*i+1;rchild=2*i+2;largest=i;
        if(A[i]<A[lchild]) largest=lchild;
        if(rchild<heapsize&&A[largest]<A[rchild]) largest=rchild;
        if(largest==i) break;
        e=A[i];A[i]=A[largest];A[largest]=e;
        i=largest;
    }
}

template<class ElemType>
void HeapSort(ElemType A[], size_t n){
    for(size_t i=n/2;i>0;i--) Heapify(A, n, i-1);
    ElemType e;
    for(size_t i=n-1;i>0;i--){
        e=A[0];A[0]=A[i];A[i]=e;
        Heapify(A, i, 0);
    }
}
