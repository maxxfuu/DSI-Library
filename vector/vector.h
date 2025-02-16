#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>

template<typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector() : data(nullptr), size(0), capacity(0) {};

    Vector(size_t s) : data(nullptr), capacity(0) {
        size = s;
    };

    //Vector(const Vector& other) {}

    ~Vector();

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

};

#endif
