#include "linkedlist.h"

int main() {
    
    // Insert at tail
    std::cout << "Insert at tail" << std::endl;
    LinkedList<std::string> ll1;
    ll1.insertAtTail("Node1");
    ll1.insertAtTail("Node2");
    ll1.insertAtTail("Node3");
    ll1.display();
    
    // Insert at head
    std::cout << "\n\nInsert at head, Node 0" << std::endl;
    ll1.insertAtHead("Node0");
    ll1.display();
    
    // Invoke Copy Constructor
    std::cout << "\n\nInvoke Copy Constructor" << std::endl;
    LinkedList<std::string> ll2 = LinkedList<std::string>(ll1);
    std::cout << "Memory Address of (ll1): " << &ll1 << std::endl;
    std::cout << "Memory Address of (ll2): " << &ll2 << std::endl;
    

    // Invoke Copy Assignment Operator
    std::cout << "\n\nInvoke Copy Assignment Operator" << std::endl;
    LinkedList<std::string> ll3 = ll2;
    std::cout << "Memory Address of (ll2): " << &ll2 << std::endl;
    std::cout << "Memory Address of (ll3): " << &ll3 << std::endl;
    
    // Invoke Move Constructor
    std::cout << "\n\nInvoke Move Constructor" << std::endl;
    LinkedList<std::string> ll4 = std::move(ll2);
    std::cout << "Memory Address of (ll2): " << &ll2 << std::endl;
    std::cout << "Memory Address of (ll4): " << &ll4 << std::endl;

    std::cout << "\n\nDisplay ll4 after moving resources from ll2" << std::endl;
    ll4.display();

    std::cout << "\n\nDisplay ll2 after moving resources to ll4" << std::endl;
    ll2.display();

    // Invoke Move Assignment Operator
    LinkedList<std::string> ll5 = ll4;
    std::cout << "Memory Address of (ll5): " << &ll5 << std::endl;
    std::cout << "Memory Address of (ll4): " << &ll4 << std::endl;

    std::cout << "\n\nDisplay ll4 after moving resources from ll2" << std::endl;
    ll4.display();

    std::cout << "\n\nDisplay ll5 after moving resources to ll5 from ll4" << std::endl;
    ll5.display();


return 0;
}
