#include <cstdio>
#include <ios>
#include <iostream>

#include "DSU.h"


int main () {

  int n = 10;

  DSU dsu(n);

  dsu.Print(n);

  dsu.Union(0, 1);
  dsu.Union(1, 2);

  dsu.Union(3, 4);
  dsu.Union(4, 5);
  dsu.Union(3, 5);

  dsu.Union(6, 7);
  dsu.Union(7, 8);

  dsu.Print(n);

  std::cout << dsu.sameComponent(1, 1);

  return 0;
}
