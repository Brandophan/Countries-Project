#ifndef NODE_H
#define NODE_H
#include <iostream>

template<typename T>
class Node {
public:
    Node<T>() {
        previous = nullptr;
        next = nullptr;
    }
    Node<T>(T data) {
        this->data = data;
        previous = nullptr;
        next = nullptr;
    }
    T data;
    Node<T>* previous;
    Node<T>* next;
};
#endif
