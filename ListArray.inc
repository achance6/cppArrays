#include "ListArray.h"
template<typename T>
ListArray<T>::ListArray(int length, T def) : len(length), def(def)
{
    for (int i = 0; i < length; i++) prepend(def);
}

template<typename T>
ListArray<T>::ListArray(const typename ListArray& other) {
    len = other.len;
    def = other.def;
    for (int i = 0; i < len; i++) prepend(def);
    Node* cur = other.head;
    while (cur != NULL) {
        std::cout << cur->data << std::endl;
        put(cur->position, cur->data);
        cur = cur->next;
    }
}

template<typename T>
ListArray<T>::~ListArray() {
    Node* cur = head;
    while (cur != NULL) {
        Node* deleted = cur;
        cur = cur->next;
        delete deleted;
    }
}

template<typename T>
T ListArray<T>::get(int position) {
    if (position < 0 || position > len) {
        std::cerr << "INVALID INDEX" << len << std::endl;
        std::exit(0);
    }
    return find(position)->data;
}

template<typename T>
void ListArray<T>::put(int position, T data) {
    //FIXME: What if user puts at -1.
    if (position < -1 || position > len) {
        std::cerr << "INVALID INDEX" << position << std::endl;
        std::exit(0);
    }
    Node* node = find(position);
    node->data = data;
}

template<typename T>
typename ListArray<T>::Node* ListArray<T>::find(int position) {
    Node* cur = head;
    for (int i = 0; i < position && cur != NULL; i++) {
        if (position == -1 && cur->position == -1) return cur;
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
