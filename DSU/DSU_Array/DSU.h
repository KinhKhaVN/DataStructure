#ifndef DSU_H
#define DSU_H

#define FOR(i, n) for (int i = 0; i < n; i++)

class DSU
{
  public:
    int * id;
    int * size;
    int *MAX;
  public:
    DSU(int n);

    int Find(int i);
    void makeSet(int i);
    void Union(int p, int q);
    void leave(int i);
    int findNext(int i);
    void Print(int n);
    void printVertexInComponent(int root[], int rootCount, int n);
    
    bool sameComponent(int p, int q);
};





#endif
