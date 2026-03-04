#include "DSU.h"

#include <iostream>
#include <cstdio>
#include <utility>


DSU::DSU(int n)
{
  id = new int[n];
  size = new int[n];
  
  FOR(i, n)
    makeSet(i);
}

void DSU::makeSet(int i)
{
  id[i] = i;
  size[i] = 1;
}

int DSU::Find(int i)
{
  return i == id[i] ? i : id[i] = Find(id[i]);
}

void DSU::Union(int p, int q)
{
  int i = Find(p);
  int j = Find(q);

  if (i == j)
    return;

  if (size[i] < size[j])
    std::swap(i, j);

  id[j] = i;
  size[i] += size[j];
}

void DSU::Print(int n)
{
  FOR(i, n)
    std::cout << id[i] << " ";

  putchar('\n');

}

bool DSU::sameComponent(int p, int q)
{
  return Find(p) == Find(q);
}

void DSU::printVertexInComponent(int root[], int rootCount, int n)
{
  FOR(i, rootCount)
  {
    std::cout << "Component " << i + 1 << ": ";
    FOR(j, n)
    {
      if (root[i] == id[j])
        std::cout << j << " ";
    }
    putchar('\n');
  }
}
