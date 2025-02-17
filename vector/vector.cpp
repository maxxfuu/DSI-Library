#include "vector.h"

int main() {

    Vector<int> vec1;

    // Invoke copy constructor
    Vector<int> vec2 = vec1;

    std::cout << &vec1 << std::endl;
    std::cout << &vec2 << std::endl;

    return 0;
}

// Helper Functions Work
