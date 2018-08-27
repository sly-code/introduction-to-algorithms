#ifndef PRIORITY_QUEQUE_H_INCLUDED
#define PRIORITY_QUEQUE_H_INCLUDED
template<class ElemType>
class Heap{
public:
    typedef enum{MAX, MIN} HeapType;
    Heap(ElemType *_p=NULL, size_t num=0,HeapType _type=MAX):type(_type),data(_p),arraysize(num),heapsize(0){}
    void heapify(size_t i);
    void build();
    void sort();
private:
    HeapType type;
    ElemType *data;
    size_t arraysize,heapsize;
};
template<class ElemType>
void Heap<ElemType>::heapify(size_t i){//assume both the left subtree and right subtree of node i are already max/min heaps
    size_t lchild,rchild,largest;
    ElemType e;
        while(i<heapsize){
            lchild=2*i+1;rchild=2*i+2;largest=i;
            if(type==MIN){
                if(lchild<heapsize&&data[lchild]<data[i]) largest=lchild;
                if(rchild<heapsize&&data[rchild]<data[largest]) largest=rchild;
            }
            else{
                if(lchild<heapsize&&data[i]<data[lchild]) largest=lchild;
                if(rchild<heapsize&&data[largest]<data[rchild]) largest=rchild;
            }
            if(largest==i) break;
            e=data[i];data[i]=data[largest];data[largest]=e;
            i=largest;
        }
    }

template<class ElemType>
void Heap<ElemType>::build(){
    heapsize=arraysize;
    for(size_t i=arraysize/2;i>0;i--) heapify(i-1);
}

template<class ElemType>
void Heap<ElemType>::sort(){
        build();
        ElemType e;
        for(size_t i=arraysize-1;i>=1;i--){
            e=data[0];data[0]=data[i];data[i]=e;
            heapsize--;
            heapify(0);
        }
}


#endif // PRIORITY_QUEQUE_H_INCLUDED
