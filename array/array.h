#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
#include <utility>
#include <stdexcept>

template<typename T>
class Array {
private:
    T* data_;
    size_t size_;

public:
    Array() : data_(nullptr), size_(0) {
    }

    Array(size_t size) : size_(size) {
        data_ = new T[size_];
    }
    
    // Copy Constructor
    Array(const T &other) : size_(other.size) {
        data_ = new T[size_];
        for (int i = 0; i < size_ - 1; i++) {
            data_[i] = other.data_[i];
        }
    }
    
    // Copy Assignment Operator
    Array& operator=(const Array &other) {
        if (this == &other) { // Self Assignment Check, a1 = a1;
            return *this;
        }

        delete[] data_; // Free exisitng memory, object already contain allocated memory
        size_ = other.size_;
        data_ = new T[size_];

        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
        return *this;
    }

    // Move Constructor
    Array(Array &&other) : data_(nullptr), size_(0) {
        data_ = other.data_;     // Transfer Resources
        size_ = other.size_;     // Transfer Resources

        other.data_ = nullptr;
        other.size_ = 0;
    }
    
    // Move Assignment Operator
    Array& operator=(Array &&other) {
        // Taking an rvalue reference to an address of a temporary object.
        if (this == &other) {
            return *this;
        }

        data_ = other.data_;
        size_= other.size_;

        other.data_ = nullptr;
        size_ = 0;

        return *this;
    }
    
    // Destructor
    ~Array() {
        delete[] data_;
    }

    // Operator Overload
    T& operator[](size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

};

#endif
