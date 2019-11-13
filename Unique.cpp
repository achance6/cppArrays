#include <iostream>
#include "SparseArray.h"

using std::cout;
using std::endl;

int main(void) {
  SparseArray<int> * array = new SparseArray<int>(6, 0);
  array->put(5, 2);
  array->put(1, 1);
  cout << array->get(1) << endl;
  cout << array->get(2) << endl;
  cout << array->length() << endl;
}

