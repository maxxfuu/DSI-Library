#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource Created\n\n"; }
    ~Resource() { std::cout << "Resource Deleted\n\n"; }

};


struct ControlBlock {
    int count;
    std::mutex mutex;
};

template<typename T>
class SharedPtr {
private:
    T* ptr_ = {nullptr};
    ControlBlock* block_ {nullptr};

public:
    // Default Constructor
    SharedPtr() : ptr_(nullptr), block_(nullptr) { }

    // Constructor With Pointer
    SharedPtr(T* ptr) : ptr_(ptr), block_(nullptr) {
        if (ptr_ != nullptr) {
            block_ = new ControlBlock{1, std::mutex()};
        }
    }
    
    // Copy Constructor (Shallow Copy)
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        if (ptr_) {
            (*ref_count_)++;
            std::cout << "SharedPtr shallowed copied, Ref count = " << *ref_count_ << "\n";
        }
    }

    // Move Constructor
    SharedPtr(SharedPtr&& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        other.ptr_ = nullptr;
        other.ref_count_ = nullptr;
    }

    ~SharedPtr() {
        if (ptr_) {
            (*ref_count_)--;
            std::cout << "SharedPtr destroyed, Ref count = " << *ref_count_ << "\n";
            if (*ref_count_ == 0) {
                delete ptr_;
                delete ref_count_;
                std::cout << "Resouce Fully Deleted";
            }
        }
    }
    
    // Member Function
    int use_count() const {
        return *ref_count_;
    }
};

#endif
