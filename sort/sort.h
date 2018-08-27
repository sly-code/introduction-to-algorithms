#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<cstddef>
template<class ElemType>
void InsertSort(ElemType A[],int n);

template<class ElemType>
void SelectSort(ElemType A[],size_t n);

template<class ElemType>
void ArrayMerge(ElemType A[],size_t p,size_t q,size_t r);

template<class ElemType>
void MergeSort(ElemType A[],size_t p,size_t r);

template<class ElemType>
void MergeSort(ElemType A[],size_t n);

template<class ElemType>
size_t Partition(ElemType A[],size_t p,size_t r);

template<class ElemType>
void QuickSort(ElemType A[],size_t p,size_t r);

void CountSort(unsigned A[],unsigned N);

template<class ElemType>
void Heapify(ElemType A[], size_t heapsize, size_t i);

template<class ElemType>
void HeapSort(ElemType A[], size_t n);
#include "sort.cpp"
#endif // SORT_H_INCLUDED
