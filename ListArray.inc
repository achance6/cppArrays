#include "ListArray.h"
template<typename T>
ListArray<T>::ListArray(int length, T def) : len(length), def(def)
{
    for (int i = 0; i < length; i++) prepend(def);
}

template<typename T>
ListArray<T>::ListArray(const typename ListArray& other) {
    ListArray<T> newList = new ListArray(len, def);
    Node* cur = other->head;
    while (cur != NULL) {
        newList->put(cur->position, cur->data);
        cur = cur->next;
    }
}

template<typename T>
T ListArray<T>::get(int position) {
    if (position < 0 || position > len) {
        throw std::out_of_range("Invalid index");
    }
    return find(position)->data;
}

template<typename T>
void ListArray<T>::put(int position, T data) {
    if (position < 0 || position > len) {
        throw std::out_of_range("Invalid Index");
    }
    Node* node = find(position);
    node->data = data;
}

template<typename T>
typename ListArray<T>::Node* ListArray<T>::find(int position) {
    Node* cur = head;
    for (int i = 0; i < position && cur != nullptr; i++) {
        cur = cur->next;
    }
    return cur;
}

template<typename T>
void ListArray<T>::prepend(T data) {
    Node* node = new Node();
    node->data = data;
    node->next = head;
    head = node;
}
