#include <iostream>
#include <string>

#include "Vector.h"



int main () {

  Vector<int> v(10, 5);

  Vector<int> v2(v);
  v2.Info();
  v2.Print();

  Vector<int> v3(10, 1);
  v3.Info();
  v3.Print();



  return 19;
}
