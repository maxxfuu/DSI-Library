#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>

class Resource {
public:
    
    Resource() { printf("Resouce %p Created\n", this); }
    ~Resource() { printf("Resouce %p Deleted\n", this); }
};

template<typename T>
class UniquePtr {
private:
    T* pointer_;

public:
    UniquePtr(T* p = nullptr) : pointer_(p) {}
    ~UniquePtr() { delete pointer_; }
    
    // Move Semantics
    UniquePtr(UniquePtr&& other) : pointer_(other.pointer_){
        other.pointer_ = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) {
        if (this != &other) {
            delete pointer_;
            this->pointer_ = other.pointer_;
            other.pointer_ = nullptr;
        }
        return *this;
    }
    
    // Member Functions
    T& operator*() const { return *pointer_; }
    T* operator->() const { return pointer_; }
    
};

#endif
