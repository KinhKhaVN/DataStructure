#include <cstdio>
#include <iostream>
#include <set>

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

  FOR(i, n)
    if (dsu.id[i] == i)
      numberOfComponents++;

  std::cout << "Number of Components: " << numberOfComponents;

  putchar('\n');

  return 20;
}
