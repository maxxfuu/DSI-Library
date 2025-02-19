#include "vector.h"

int main() {

    Vector<int> vec1;

    // Invoke copy constructor
    Vector<int> vec2 = vec1;

    std::cout << &vec1 << std::endl;
    std::cout << &vec2 << std::endl;
    
    // Prior to the transfer of resources
    vec1.push_back(9); // Push value 9 to the vector
    vec1.getData(0); // Get the value in the first index
    
    // Invoke Move Constructor
    Vector<int> vec3 = std::move(vec1);
    
    // Invoking getData on vec1 should result in segmentation fault
    // vec1.getData(0);
    
    // Invoking getData on vec3 will be fine since the resource has been transfered
    vec3.getData(0);

    return 0;
}

// Helper Functions Work
