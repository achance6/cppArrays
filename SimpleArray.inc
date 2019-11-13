#include "SimpleArray.h"
template<typename T>
T SimpleArray<T>::get(int position) {
    if (position < 0 || position > len) {
        std::cerr << "INVALID POS" << std::endl;
        std::exit(0);
    }
    return find(position)->data;
}
template<typename T>
void SimpleArray<T>::put(int position, T data) {
    if (position < 0 || position > len) {
        std::cerr << "INVALID POS" << std::endl;
        std::exit(0);
    }
    Node* node = find(position);
    if (node == nullptr) {
        prepend(position, data);
    }
    else {
        node->data = data;
    }
}

template<typename T>
typename SimpleArray<T>::Node* SimpleArray<T>::find(int position) {
    Node* cur = head;
    while (cur != nullptr && cur->position != position) {
        cur = cur->next;
    }
    return cur;
}

template<typename T>
void SimpleArray<T>::prepend(int position, T data) {
    Node* node = new Node();
    node->position = position;
    node->data = data;
    node->next = head;
    head = node;
}
