#include <iostream>
#include "graph.h"
#include <fstream>
using namespace std;

int main(){
    ifstream infile("DG.txt");
    ALGraph aG(Graph::DG);
    aG.Create(infile);
    aG.Display();
    infile.seekg(0,ios::beg);
    MGraph mG(Graph::DG);
    mG.Create(infile);
    mG.Display();
    cout<<"\naG BFS: ";aG.BFSTraverse();
    cout<<"\nmG BFS: ";mG.BFSTraverse();
    cout<<"\naG DFS: ";aG.DFS(1);
    cout<<"\nmG DFS: ";mG.DFS(0);
    cout<<"\naG topological sort: ";aG.TopologicalSort();
    cout<<"\nmG topological sort: ";mG.TopologicalSort();
    return 0;
}
