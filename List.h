#ifndef LIST_H
#define LIST_H

#include <iomanip>
#include <iostream>
#include "Node.h"
#include "Data.h"
#include "Sorting.h"

template <typename T>
class Iterator;

template <typename T>
class List {
public:
    List();
    void push_back(T element);
    void insert(Iterator<T> iter, T element);
    void swap(Node<T>* node1, Node<T>* node2);
    Iterator<T> erase(Iterator<T> iter);
    Iterator<T> begin();
    Iterator<T> end();
    Node<T>* start();
    Node<T>* ending();
private:
    Node<T>* first;
    Node<T>* last;
    friend class Iterator<T>;
};
template <typename T>
List<T>::List() {
    this->first = nullptr;
    this->last = nullptr;
}

template <typename T>
void List<T>::push_back(T element) {
    Node<T>* new_node = new Node<T>(element);
    if (last == nullptr) {
        this->first = new_node;
        this->last = new_node;
    }
    else {
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
}

template <typename T>
void List<T>::insert(Iterator<T> iter, T element) {
    if (iter.position == nullptr) {
        push_back(element);
        return;
    }
    Node<T>* after = iter.position;
    Node<T>* before = after->previous;
    Node<T>* new_node = new Node<T>(element);
    new_node->previous = before;
    new_node->next = after;
    after->previous = new_node;
    if (before == nullptr) {
        first = new_node;
    }
    else {
        before->next = new_node;
    }
}

template <typename T>
void List<T>::swap(Node<T>* node1, Node<T>* node2) {
    if (node1 == node2)
    {
        return;
    }
    Node<T>* after = node1->next;
    Node<T>* before = node1->previous;
    Node<T>* after2 = node2->next;
    Node<T>* before2 = node2->previous;

    // If node1 and node2 are adjacent
    if (after == node2) {
        node1->next = after2;
        node1->previous = node2;
        node2->next = node1;
        node2->previous = before;
    }
    else if (after2 == node1) {
        node2->next = after;
        node2->previous = node1;
        node1->next = node2;
        node1->previous = before2;
    }
    else {
        node1->next = after2;
        node1->previous = before2;
        node2->next = after;
        node2->previous = before;
    }

    if (after != nullptr && after != node2) {
        after->previous = node2;
    }
    if (before != nullptr && before != node2) {
        before->next = node2;
    }

    if (after2 != nullptr && after2 != node1) {
        after2->previous = node1;
    }
    if (before2 != nullptr && before2 != node1) {
        before2->next = node1;
    }

    if (first == node1) {
        first = node2;
    }
    else if (first == node2) {
        first = node1;
    }

    if (last == node1) {
        last = node2;
    }
    else if (last == node2) {
        last = node1;
    }
}
template <typename T> Iterator<T> List<T>::erase(Iterator<T> iter) {
    Node<T>* remove = iter.position;
    Node<T>* before = remove->previous;
    Node<T>* after = remove->next;
    if (remove == first) {
        first == after;
    }
    else {
        before->next = after;
    }
    if (remove == last) {
        last = before;
    }
    else {
        after->previous = before;
    }
    delete remove;
    Iterator<T> r;
    r.position = after;
    r.container = this;
    return r;
}
template <typename T> Iterator<T> List<T>::begin() {
    Iterator<T> iter;
    iter.position = first;
    iter.container = this;
    return iter;
}
template <typename T>
Iterator<T> List<T>::end() {
    Iterator<T> iter;
    iter.position = last;
    iter.container = this;
    return iter;
}
template <typename T>
Node<T>* List<T>::start()
{
    return first;
}
template <typename T>
Node<T>* List<T>::ending()
{
    return last;
}
template <typename T>
class Iterator {
public:
    Iterator<T>();
    Iterator(const Iterator& other);
    T get() const;
    void next();
    void previous();
    bool equals(Iterator other) const;
    Node<T>* getPosition() const;
private:
    Node<T>* position;
    List<T>* container;
    Data* data;
    friend class List<T>;
};
template <typename T>
Iterator<T>::Iterator()
{
    this->position = nullptr;
    this->container = nullptr;
}
template <typename T>
Iterator<T>::Iterator(const Iterator<T>& other) {
    position = other.position;
    container = other.container;
    data = other.data;
}

template <typename T> Node<T>* Iterator<T>::getPosition() const { return this->position; }
template <typename T> T Iterator<T>::get() const { return position->data; }
template <typename T> void Iterator<T>::next() {
    position = position->next;
}
template <typename T> void Iterator<T>::previous() {
    if (position == nullptr) {
        position = container->last;
    }
    else {
        position = position->previous;
    }
}
template <typename T> bool Iterator<T>::equals(Iterator other) const {
    return position == other.position;
}
#endif
