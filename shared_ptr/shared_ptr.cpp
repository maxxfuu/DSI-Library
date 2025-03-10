#include "shared_ptr.h"

int main() {
    SharedPtr<Resource> obj1(new Resource);
    SharedPtr<Resource> obj2 = obj1;
    SharedPtr<Resource> obj3 = obj2;

}
