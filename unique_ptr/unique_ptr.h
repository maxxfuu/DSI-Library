#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>

class Resource {
public:
    Resource() {std::cout << "Resource Created";}
    ~Resource() {std::cout << "Resource Deleted";}
};

class UniquePtr {
public:
    UniquePtr() {

    }
private:

};

#endif
