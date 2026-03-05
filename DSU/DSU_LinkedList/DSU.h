#ifndef DSU_H
#define DSU_H

#include <vector>
#define FOR(i, n) for (int i = 0; i < n; i++)

class Node
{
  public:
    int data;
    Node * next;
    Node * tail;
  public:
    Node(int value);
};

typedef std::vector<Node *> nodeList ;

class DSU
{
  public:
    nodeList nodes;
    std::vector<int> size;
    DSU(int n);
  public:
    void makeSet(int i);
    Node * Find(int i);
    void Union(int p, int q);
    void Print();
};





#endif
