#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>

class Resource {
public:
    Resource() { std::cout << "Resource Created\n\n"; }
    ~Resource() { std::cout << "Resource Deleted\n\n"; }

};

template<typename T>
class SharedPtr {
private:
    T* ptr_;
    int* ref_count_;

public:
    SharedPtr(T* ptr = nullptr) : ptr_(ptr), ref_count_(new int(1)) {
        if (ptr) { // If ptr is 
            std::cout << "SharedPtr created, Ref count = " << *ref_count_ << "\n";
        }
    }
    
    // Copy Constructor (Shallow Copy)
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        if (ptr_) {
            (*ref_count_)++;
            std::cout << "SharedPtr shallowed copied, Ref count = " << *ref_count_ << "\n";
        }
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
