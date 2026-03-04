#include "DSU.h"

#include <iostream>
#include <cstdio>
#include <utility>


DSU::DSU(int n)
{
  id = new int[n];
  size = new int[n];
  lab = new int[n];
  
  FOR(i, n)
    makeSet(i);
}

void DSU::makeSet(int i)
{
  lab[i] = -1;
}

int DSU::Find(int i)
{
  return lab[i] < 0 ? i : lab[i] = Find(lab[i]);
}

void DSU::Union(int p, int q)
{
  int i = Find(p);
  int j = Find(q);

  if (i == j)
    return;

  if (lab[i] < lab[j])
    std::swap(i, j);

  lab[j] = i;
  lab[i] += lab[j];
}

void DSU::Print(int n)
{
  FOR(i, n)
    std::cout << lab[i] << " ";

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
