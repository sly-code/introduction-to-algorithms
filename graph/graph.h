#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include<vector>
#include<istream>
class Iterator;
class ALIterator;
class MIterator;
class Graph{
public:
    typedef enum{DG, DN, AG, AN} GraphKind;
    typedef std::string VertexType;
    typedef int WeightType;
    Graph(GraphKind _kind):kind(_kind),vernum(0),arcnum(0){}
    virtual ~Graph(){}
    void Create(std::istream &);
    virtual void Display() const =0;
    virtual void InsertVex(const VertexType &v)=0;
    virtual void InsertArc(const VertexType &u, const VertexType &v,const WeightType &w)=0;
    void BFSTraverse() const;
    void DFS(size_t i)const;
    void DFSTraverse()const;
    void visit(size_t i) const;
    void TopologicalSort() const;
    virtual void Clear()=0;
    virtual Iterator* createIterator() const =0;
protected:
    size_t LocateVex(const VertexType &) const;
    GraphKind kind;
    unsigned vernum;
    unsigned arcnum;
private:
    virtual const VertexType& GetVex(size_t i) const =0;
    virtual size_t FirstAdjVex(size_t i) const =0;
    virtual size_t NextAdjVex(size_t v, size_t w) const =0;
};

class ALGraph:public Graph{
    friend class ALIterator;
public:
    ALGraph(GraphKind _kind=AG):Graph(_kind){}
    ~ALGraph();
    virtual void Display() const;
    virtual void InsertVex(const VertexType &v);
    virtual void InsertArc(const VertexType &,const VertexType &,const WeightType &);
    virtual void Clear();
    virtual Iterator* createIterator() const;
private:
    virtual const VertexType& GetVex(size_t i) const;
    virtual size_t FirstAdjVex(size_t i) const;
    virtual size_t NextAdjVex(size_t v, size_t w) const;
private:
    typedef struct ArcNode{
        size_t adjvex;
        WeightType weight;
        struct ArcNode *nextarc;
    }ArcNode;
    typedef struct VNode{
        VertexType data;
        ArcNode *firstarc;
    }VNode;
    std::vector<VNode> vertices;
};

class MGraph:public Graph{
    friend class MIterator;
public:
    MGraph(GraphKind _kind=AG):Graph(_kind),NO_LINK((_kind==DN||_kind==AN)?INF:0){}
    virtual void Display() const;
    virtual void InsertVex(const VertexType &v);
    virtual void InsertArc(const VertexType &,const VertexType &,const WeightType &);
    virtual void Clear();
    Iterator* createIterator() const;
private:
    virtual const VertexType& GetVex(size_t i) const;
    virtual size_t FirstAdjVex(size_t i) const;
    virtual size_t NextAdjVex(size_t v, size_t w) const;
private:
    std::vector<VertexType> vertices;
    std::vector<std::vector<WeightType> > arcs;
    const WeightType INF=INT_MAX;
    const WeightType NO_LINK;
};
#endif // GRAPH_H_INCLUDED
