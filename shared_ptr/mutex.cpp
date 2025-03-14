#include <iostream>
#include <thread>

void test(int x) {
    std::cout << "Hello from thread!" << std::endl;
    std::cout << "Argument Passed In: " << x << std::endl;
}

int main() {
    // pass in the address of the function, and a int 
    std::thread myThread(&test, 100);
    myThread.join(); // Blocks the current thread until the thread indentified by *this finsihes its executions.
    
    auto lambda=[](int x) {
        std::cout << "Hello from thread 2" << std::endl;

    };

    std::thread myThread2(lambda, 100);
    myThread2.join();

    std::cout << "Hello from the main thread" << std::endl;

    return 0;
}

// We can think of threads as a lightweight process that shares the same private memory space
// given by the OS. In the program we will have a main thread, main(). However, in the program we
// can also have another thread, func(). It shares the same code, same library potentially some 
// of the same data as well. 
//
//  std::thread, introduced in C++11.
