#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList{
private:
    struct Node{
        T data;
        Node* next;

        // Default Constrcutor for structs
        Node(const T& val) : data(val), next(nullptr){};
    };
    
    // Data Members
    Node* head;
    Node* tail;
    
    void clear() {
        // Free Memory
        while(head) {
            Node* temp = head; // New ptr pointing to the same memory location as head, which is the first node.
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void deepCopy(const LinkedList& other) {
        Node* current = other.head;
        while(current) {
            insertAtEnd();
        }
    }

public:

    // Default Constructor
    LinkedList() : head(nullptr), tail(nullptr){}
    
    // Copy Constuctor (Deep Copy)
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr) {}
    
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
        }

    }

    ~LinkedList() {
    }
    
    void insertAtEnd(const T& value) {
        Node* newNode = new Node(value);
        newNode->data = value;
        newNode->next 
    }

};

#endif
