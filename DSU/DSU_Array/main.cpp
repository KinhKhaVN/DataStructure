#include <cstdio>
#include <ios>
#include <iostream>

#include "DSU.h"


int main () {

  int n = 10;
  DSU dsu(n);

  dsu.Print(n);

  dsu.Union(1, 3);
  dsu.Union(4, 6);
  dsu.Union(0, 2);
  dsu.Union(7, 8);
  dsu.Union(0, 1);
  dsu.Union(4, 5);
  dsu.Union(1, 2);

  dsu.Print(n);

  FOR(i, n)
    std::cout << dsu.size[i] << " ";
  putchar('\n');

  int numberOfComponents = 0;

  int root[n];
  int rootCount= 0;

  FOR(i, n)
  {
    if (dsu.id[i] == i)
    {
      numberOfComponents++;
      root[rootCount++] = i;
    }
  }
  std::cout << "Number of Components: " << numberOfComponents;

  putchar('\n');

  FOR(i, rootCount)
    std::cout << root[i] << " ";

  putchar('\n');

  dsu.printVertexInComponent(root, rootCount, n);



  return 0;
}
