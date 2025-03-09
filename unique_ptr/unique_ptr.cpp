#include "unique_ptr.h"

int main() {
    Resource* obj1 = new Resource();

    UniquePtr<Resource> up(new Resource());

    return 0; // obj1 never destroyed. Use, unqiue_ptr to destroy when obj is out of scope.
}


