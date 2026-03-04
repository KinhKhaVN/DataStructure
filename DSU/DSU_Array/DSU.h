#ifndef DSU_H
#define DSU_H

#define FOR(i, n) for (int i = 0; i < n; i++)

class DSU
{
  public:
    int * id;
    int * size;
  public:
    DSU(int n);

    int Find(int i);
    void makeSet(int i);
    void Union(int p, int q);
    void Print(int n);
};





#endif
