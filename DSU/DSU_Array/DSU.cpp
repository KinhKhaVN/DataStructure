#include "DSU.h"

#include <iostream>
#include <cstdio>
#include <utility>


DSU::DSU(int n)
{
  id = new int[n];
  size = new int[n];
  minimum = new int[n];
  sum = new int[n];
  value = new int[n];

  FOR(i, n)
    makeSet(i);
}

void DSU::makeSet(int i)
{
  id[i] = i;
  size[i] = 1;
  value[i] = i;
  minimum[i] = value[i];
  sum[i] = value[i];
}

int DSU::Find(int i)
{
  return id[i] == i ? i : id[i] = Find(id[i]);
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
  sum[i] += sum[j];
  minimum[i] = std::min(minimum[i], minimum[j]);
}

void DSU::Print(int n)
{
  FOR(i, n)
    std::cout << id[i] << " ";

  putchar('\n');

  FOR(i, n)
    std::cout << size[i] << " ";

  putchar('\n');
  FOR(i, n)
    std::cout << minimum[i] << " ";

  putchar('\n');
  FOR(i, n)
    std::cout << sum[i] << " ";

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

