#include <cstdio>
#include <ios>
#include <iostream>

#include "DSU.h"


int main () {

  int n, query;
  
  std::cin >> n >> query;

  DSU dsu(n);

  FOR(step, query)
  {
    int q, u , v;
    std::cin >> q >> u >> v;

    if (q == 0)
      dsu.Union(u, v);
    if (q == 1)
      std::cout << dsu.sameComponent(u, v) << '\n';
  }


  return 0;
}
