#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>

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
    size_t size;
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
            insertAtTail(current->data);
            current = current->next;
        }
    }

public:
    // Default Constructor
    LinkedList() : size(0), head(nullptr), tail(nullptr){}
    
    // Copy Constuctor (Deep Copy)
    LinkedList(const LinkedList& other) : size(0), head(nullptr), tail(nullptr) {
        deepCopy(other);
    }
    
    // Copy Assignment Operator (Deep Copy)
    LinkedList& operator=(const LinkedList& other) {
        if (this != &other) {
            clear();
        }
    }
    
    // Move Constructor (Transfer Resource)
    LinkedList(LinkedList&& other) : head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    // Move Assignment Operator (Transfer Resource)
    LinkedList& operator=(LinkedList&& other) {
        
    }

    // Destructor
    ~LinkedList() {
        clear();
    }
    
    // Member Functions
    void insertAtTail(const T& value) {
        Node* newNode = new Node(value); // New node to be added.
        if(!head) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode; // Attach newNode to at the end of LinkedList
        tail = newNode; // Update Tail Pointer
        return;
    }

    void insertAtHead(const T& value) {
        Node* newNode = new Node(value);
        Node* temp = head;
        head = newNode;
        newNode->next = temp;
        return;
    }
    
    void display() const {
        Node* curr = head;
        std::cout << "HEAD->";
        while(curr) {
            std::cout << curr->data << "->";
            curr = curr->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void nodeMemory() {
    }
};

#endif
