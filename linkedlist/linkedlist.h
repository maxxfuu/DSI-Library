#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {
    }
};

template<typename T>
class Linkedlist {
private:
Node<T>* head;
Node<T>* tail;

public:

    // Default Constructor
    Linkedlist() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~Linkedlist() {}
};

#endif
