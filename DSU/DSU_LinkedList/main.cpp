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

  int countComponent = 0;

  for (int i = 0; i < (int) dsu.nodes.size(); i++)
    if (dsu.nodes[i]->tail->data == i) 
      countComponent++;

  std::cout << "Number or Components: " << countComponent << '\n';


  return 0;
}
