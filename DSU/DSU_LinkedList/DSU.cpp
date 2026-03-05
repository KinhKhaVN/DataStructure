#include "DSU.h"

#include <iostream>
#include <cstdio>
#include <utility>


Node::Node(int value): data(value), next(NULL), tail(this) {}


DSU::DSU(int n)
{
  nodes.resize(n);
  size.resize(n, 1);

  FOR(i, n)
    nodes[i] = new Node(i);
}

Node * DSU::Find(int i)
{
  return nodes[i]->tail;
}

void DSU::Union(int p, int q)
{
  Node * I = Find(p);
  Node * J = Find(q);

  if (I == J)
    return;

  if (size[I->data] < size[J->data])
    std::swap(I, J);

  Node * tmp = I;

  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = J;

  tmp = J;
  while (tmp != NULL)
  {
    tmp->tail = I;
    tmp = tmp->next;
  }

  size[I->data] += size[J->data];
}

void DSU::Print()
{
  for (size_t i = 0; i < nodes.size(); i++)
    std::cout << nodes[i]->tail->data << " ";

  putchar('\n');
}

