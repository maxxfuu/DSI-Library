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

    struct ControlBlock {
        int count_;
        std::mutex mutex_;

        ControlBlock(int c) : count_(c) {};
    };

    T* ptr_;
    ControlBlock* control_;

    void release() {}

public:
    // Default Constructor
    SharedPtr() : ptr_(nullptr), control_(nullptr) {}
    
    // Constructor with Pointers
    SharedPtr(T* ptr, ControlBlock* control) : ptr_(ptr), control_(ptr_ ? new ControlBlock(1) : nullptr) {
        if (ptr_) {
            std::cout << "New Shared Pointer Created. Reference Count = " << control->count_ << std::endl;
        }
    }

    // Copy Constructor (Shallow Copy)
    //  Invoked when SharedPtr ptr1(ptr2);
    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), control_(other.control_) {
        if (control_) {
            // Implement Multithread Logic
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
