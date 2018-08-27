#ifndef ITERATOR_H_INCLUDED
#define ITERATOR_H_INCLUDED
#include "graph.h"
class Iterator{
public:
    virtual void first()=0;
    virtual void next()=0;
    virtual bool isdone() const =0;
    virtual size_t current() const=0;
    virtual void setv(size_t _i){i=_i;}
    virtual ~Iterator(){}
protected:
    size_t i;
};
class ALIterator:public Iterator{
public:
    ALIterator(const ALGraph *_g=NULL):g(_g){}
    void first(){p=g->vertices[i].firstarc;}
    void next(){p=p->nextarc;}
    bool isdone() const {return p==NULL;}
    size_t current() const{return p->adjvex;}
private:
    ALGraph::ArcNode *p;
    const ALGraph *g;
};
class MIterator:public Iterator{
public:
    MIterator(const MGraph *_g=NULL):g(_g){}
    void first(){
        for(cur=0;cur<g->vernum && g->arcs[i][cur]==g->NO_LINK;cur++) ;
    }
    void next(){
        for(cur++;cur<g->vernum && g->arcs[i][cur]==g->NO_LINK;cur++) ;
    }
    bool isdone() const {return cur==g->vernum;}
    size_t current() const {return cur;}
private:
    size_t cur;
    const MGraph *g;
};

#endif // ITERATOR_H_INCLUDED
