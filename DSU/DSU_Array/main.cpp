#include <cstdio>
#include <ios>
#include <iostream>

#include "DSU.h"


int main () {

  int n = 6;

  DSU dsu(n);

//  dsu.Print(n);

  dsu.leave(2);
  dsu.leave(3);
  dsu.leave(1);
  std::cout << dsu.findNext(2) << '\n';
  std::cout << dsu.findNext(3) << '\n';
  std::cout << dsu.findNext(1) << '\n';

  dsu.Print(n);


  return 0;
}
