#ifndef SPARSEARRAY_H
#define SPARSEARRAY_H

#include "Array.h"
/* An array implemented using a linked list. Useful for storing large amounts of data
with few variations because of the memory saving feature of not storing a default value.
*/
template<typename T>
class SparseArray : public Array<T> {
public:
  SparseArray(int length, T def);
  T get(int position);
  void put(int position, T data);
  int length() { return len; }

private:
	T def;
    //Representation of an position
	class Node {
    public:
        //Make code analysis happy
        Node(T data = T(), Node * next = nullptr, int position = -1): data(data), next(next), position(position){}
		T data;
		Node * next;
		int position;
    };
  int len;
  Node * head;
  Node * find(int position);
  void prepend(int position, T data);
  
};

#include "SparseArray.inc"
#endif
