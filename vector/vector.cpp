#include "vector.h"

int main() {

    Vector<int>* vec = new Vector<int>();
    vec->getCapacity();
    vec->push_back(4);

    vec->getCapacity();
    vec->getData(1);

return 0;
}
