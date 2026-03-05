#include <cstdio>
#include <ios>
#include <iostream>

#include "DSU.h"


int main () {

  int n = 5;
  DSU dsu(n);

  dsu.Union(0, 1);
  dsu.Union(2, 3);

  dsu.Print();

  std::cout << ( dsu.Find(1) == dsu.Find(4)) << '\n';


  return 0;
}
