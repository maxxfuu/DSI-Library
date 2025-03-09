#include "unique_ptr.h"

int main() {
    Resource* obj1 = new Resource();
    return 0; // Resource never destroyed. Use, unqiue_ptr to destroy when obj is out of scope.
}
