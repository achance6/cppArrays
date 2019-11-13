#ifndef SIMPLEARRAY_H
#define SIMPLEARRAY_H
#include "Array.h"

template<typename T>
class SimpleArray : Array<T> {
public:
    SimpleArray(int length, T def) : len(length), def(def) {}
    T get(int position);
    void put(int position, T data);
    int length() { return len; }
private:
    T def;
    class Node {
    public:
        Node(T data = T(), Node* next = nullptr, int position = -1) : data(data), next(next), position(position) {}
        T data;
        Node* next;
        int position;
    };
    int len;
    Node* head;
    Node* find(int position);
    void prepend(int position, T data);
};

#include "SimpleArray.inc"
#endif 

