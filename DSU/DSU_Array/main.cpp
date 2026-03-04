#include <cstdio>
#include <ios>
#include <iostream>

#include "DSU.h"


int main () {

  int n = 10;

  DSU dsu(n);

//  dsu.Print(n);

  dsu.Union(0, 1);
  dsu.Union(1, 2);
  dsu.Union(2, 3);
  dsu.Union(3, 4);

  dsu.Union(5, 6);
  dsu.Union(6, 7);
  dsu.Union(7, 8);
  dsu.Union(8, 9);

  dsu.Print(n);


  return 0;
}
