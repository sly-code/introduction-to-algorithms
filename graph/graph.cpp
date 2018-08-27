#include "graph.h"
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include "Iterator.h"
size_t Graph::LocateVex(const VertexType &u)const{
    size_t i=0;
    while(GetVex(i)!=u && i<vernum) i++;
    if(i>=vernum) return UINT_MAX;
    else return i;
}

void Graph::Create(std::istream &in){
    std::string line;
    getline(in, line);
    std::istringstream strm(line);
    VertexType u,v;
    WeightType w=1;
    while(strm>>v)
        InsertVex(v);
    while(getline(in, line)){
        strm.clear();
        strm.str(line);
        strm>>u>>v;
        if(kind==DN||kind==AN) strm>>w;
        InsertArc(u, v, w);
        arcnum++;
        if(kind==AG||kind==AN) InsertArc(v, u, w);
    }
    in.clear();
}

const Graph::VertexType& ALGraph::GetVex(size_t i) const{
    return vertices[i].data;
}

const Graph::VertexType& MGraph::GetVex(size_t i) const{
    return vertices[i];
}

void Graph::DFS(size_t i) const{
    std::vector<bool> visited(vernum, false);
    std::stack<size_t> S;
    visit(i);visited[i]=true;
    S.push(i);
    size_t last_pop=UINT_MAX, t, w;
    while(!S.empty()){
        t=S.top();
        w=(last_pop==UINT_MAX?FirstAdjVex(t):NextAdjVex(t, last_pop));
        while(w!=UINT_MAX&&visited[w]) w=NextAdjVex(t, w);
        if(w==UINT_MAX){S.pop();last_pop=t;}
        else {visit(w);visited[w]=true;S.push(w);}
    }
}
void Graph::DFSTraverse()const {}

void Graph::BFSTraverse() const{
    std::vector<bool> visited(vernum, false);
    std::queue<size_t> Q;
    size_t w;
    Iterator* itr=createIterator();
    for(size_t i=0;i<vernum;i++){
        if(!visited[i]){//start from vertex i and execute BFS for once
            visit(i);visited[i]=true;Q.push(i);
            while(!Q.empty()){
                itr->setv(Q.front());
                for(itr->first();!itr->isdone();itr->next()){
                    w=itr->current();
                    if(!visited[w]){
                        visit(w); visited[w]=true; Q.push(w);
                    }
                }
                Q.pop();
            }
        }//end if
    }
    delete itr;
}

void Graph::visit(size_t i) const{
    std::cout<<GetVex(i)<<' ';
}

void Graph::TopologicalSort() const{
    std::vector<unsigned> inDegree(vernum,0);
    size_t i,j;
    Iterator* itr=createIterator();
    for(i=0;i<vernum;i++){
        itr->setv(i);
        for(itr->first();!itr->isdone();itr->next())
            inDegree[itr->current()]++;
    }
    std::stack<size_t> S;
    for(i=0;i<vernum;i++)
        if(!inDegree[i]) S.push(i);
    unsigned cnt=0;
    while(!S.empty()){
        i=S.top();visit(i);S.pop();cnt++;
        itr->setv(i);
        for(itr->first();!itr->isdone();itr->next()){
            j=itr->current();
            inDegree[j]--;
            if(!inDegree[j]) S.push(j);
        }
    }
    delete itr;
    if(cnt<vernum) std::cout<<"\noutput vertex number: "<<cnt<<" ,loop exists\n";
}

void ALGraph::InsertVex(const VertexType &v){
     VNode vnode={v, NULL};
     vertices.push_back(vnode);
     vernum++;
 }

void MGraph::InsertVex(const VertexType &v){
     vertices.push_back(v);
     for(size_t i=0;i<vernum;i++) arcs[i].push_back(NO_LINK);
     vernum++;
     std::vector<WeightType> wvec(vernum, NO_LINK);
     arcs.push_back(wvec);
}

void ALGraph::InsertArc(const VertexType &u, const VertexType &v, const WeightType &w){
    size_t i=LocateVex(u);
    size_t j=LocateVex(v);
    if(i!=UINT_MAX && j!=UINT_MAX){
        ArcNode *p=new ArcNode;
        p->adjvex=j;
        p->nextarc=NULL;
        p->weight=w;
        ArcNode *q=vertices[i].firstarc;
        if(!q) vertices[i].firstarc=p;
        else{
            while(q->nextarc) q=q->nextarc;
            q->nextarc=p;
        }
    }
}

void MGraph::InsertArc(const VertexType &u, const VertexType &v, const WeightType &w){
    size_t i=LocateVex(u);
    size_t j=LocateVex(v);
    if(i!=UINT_MAX && j!=UINT_MAX)
        arcs[i][j]=w;
}

void ALGraph::Display()const{
    ArcNode *p=NULL;
    for(size_t i=0;i<vertices.size();i++){
        std::cout<<i<<' '<<vertices[i].data;
        p=vertices[i].firstarc;
        while(p){
            std::cout<<"--->"<<vertices[p->adjvex].data;
            if(kind==AN||kind==DN)
                std::cout<<','<<p->weight;
            p=p->nextarc;
        }
        std::cout<<std::endl;
    }
    std::cout<<"vernum="<<vernum<<" arcnum="<<arcnum<<std::endl;
}

void MGraph::Display()const{
     for(size_t m=0;m<vernum;m++){
		for(size_t n=0;n<vernum;n++){
            if(arcs[m][n]!=INF) std::cout<<arcs[m][n]<<' ';
            else std::cout<<"Inf ";
		}
		std::cout<<std::endl;
	}
    std::cout<<"vernum="<<vernum<<" arcnum="<<arcnum<<std::endl;
}

size_t ALGraph::FirstAdjVex(size_t i) const{
    ArcNode *p=vertices[i].firstarc;
    if(p) return p->adjvex;
    else return UINT_MAX;
}
size_t MGraph::FirstAdjVex(size_t v) const{
    size_t i=0;
	while(i<vernum && arcs[v][i]==NO_LINK) i++;
	if(i>=vernum) return UINT_MAX;
	else return i;
}
size_t ALGraph::NextAdjVex(size_t v, size_t w) const{
    ArcNode *p=vertices[v].firstarc;
    while(p&&p->adjvex!=w) p=p->nextarc;
    if(!p||!p->nextarc) return UINT_MAX;
    else return p->nextarc->adjvex;
}
size_t MGraph::NextAdjVex(size_t v, size_t w) const{
    size_t i=w+1;
	while(i<vernum && arcs[v][i]==NO_LINK) i++;
	if(i>=vernum) return UINT_MAX;
	else return i;
}

void ALGraph::Clear(){
    ArcNode *p,*q;
    for(size_t i=0;i<vernum;i++){
        p=vertices[i].firstarc;
        while(p){
            q=p->nextarc;
            delete p;
            p=q;
        }
    }
    vertices.clear();
}

void MGraph::Clear(){
    vertices.clear();
    arcs.clear();
}
ALGraph::~ALGraph(){
    Clear();
}
Iterator* ALGraph::createIterator() const {return new ALIterator(this);}
Iterator* MGraph::createIterator() const {return new MIterator(this);}
