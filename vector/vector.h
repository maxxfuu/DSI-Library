#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>

template<typename T>
class Vector {
public:
    // Default Constructor
    Vector() : data(nullptr), size(0), capacity(0) {};

    // Default Constructor w/ size parameter
    Vector(size_t s) : data(nullptr), capacity(0) {
        size = s;
    };

    // Variadic Constructor
    template<typename... Args>
    Vector(Args&&... args) : data(nullptr), size(0), capacity(0) {
        (push_back(std::forward<Args>(args)), ...);
    }

    // Copy Constructor
    Vector(const Vector<T>& other) {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    };
    
    // Copy Assignment Operator
    Vector<T>& operator=(const Vector& other) {
        if (this == &other) {
            return this;
        }
        // Free exisiting resource occupied
        delete[] data;

        size = other.size;
        data = new T[other.capacity];

        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Move Consturtor
    Vector(Vector&& other) : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Move Assignmnet Operator
    Vector& operator=(Vector&& other) {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;
            capacity = other.capacity;

            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        delete[] data;
    }

    void push_back(T value) {
        if (size == capacity) {
            if (size == 0) {
                capacity = 1;
            } else {
                capacity *= 2;
            }

            T* newData = new T[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }
        /* std::cout << "currnet size before push back" << size << std::endl;
        std::cout << "currnet value to be pushed" << value << std::endl; */
        data[size++] = value;
    }

    void getCapacity() {
        std::cout << "Current Capacity: " << this->capacity << std::endl;
    }

    void getSize() {
        std::cout << "Current Size: " << this->size << std::endl;
    }

    void getData(int index) {
        std:: cout << "Data of index " << index << ": " << this->data[index] << std::endl;
    }

private:
    T* data;
    size_t size;
    size_t capacity;


};

#endif
