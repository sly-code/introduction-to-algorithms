#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include "sort.h"
using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;

const unsigned N=100000;

template<class ElemType>
void PrintArray(ElemType A[],unsigned n){
    for(size_t i=0;i<n;i=i+(n>20?n/20:1))
        cout<<A[i]<<' ';
    cout<<endl;
}
void InitArray(unsigned A[], ifstream &infile){
    infile.clear();
    infile.seekg(0, std::ios::beg);
    for(size_t i=0;infile;i++) infile>>A[i];
}


int main(){
    unsigned *p=new unsigned[N];
    srand((unsigned)time(NULL));
    ofstream outfile("data.txt");
    for(unsigned i=1;i<=N;i++){
        outfile<<rand()<<' ';
        if(i%20==0) outfile<<'\n';
    }
    outfile.close();
    ifstream infile("data.txt");

    InitArray(p,infile);
    cout<<"The initial array is"<<endl;
    PrintArray(p,N);

    time_t start,ending;

    InitArray(p,infile);start=clock();CountSort(p,N);ending=clock();
    cout<<"Count sort running time="<<double(ending-start)/CLOCKS_PER_SEC<<endl;
    PrintArray(p,N);

    InitArray(p,infile);start=clock();QuickSort(p,0,N-1);ending=clock();
    cout<<"Quick sort running time="<<double(ending-start)/CLOCKS_PER_SEC<<endl;
    PrintArray(p,N);

    InitArray(p,infile);start=clock();HeapSort(p,N);ending=clock();
    cout<<"Heap sort running time="<<double(ending-start)/CLOCKS_PER_SEC<<endl;
    PrintArray(p,N);


    InitArray(p,infile);start=clock();MergeSort(p,0,N-1);ending=clock();
    cout<<"Merge sort recursive running time="<<double(ending-start)/CLOCKS_PER_SEC<<endl;
    PrintArray(p,N);

    InitArray(p,infile);start=clock();MergeSort(p,N);ending=clock();
    cout<<"Merge sort non-recursive running time="<<double(ending-start)/CLOCKS_PER_SEC<<endl;
    PrintArray(p,N);

    InitArray(p,infile);start=clock();SelectSort(p,N);ending=clock();
    cout<<"Select sort running time="<<double(ending-start)/CLOCKS_PER_SEC<<endl;
    PrintArray(p,N);

    InitArray(p,infile);start=clock();InsertSort(p,N);ending=clock();
    cout<<"Insert sort running time="<<double(ending-start)/CLOCKS_PER_SEC<<endl;
    PrintArray(p,N);

    delete[] p;
}
