#include <iostream>
#include "src/singly-linked-list/StaticLinkedList.h"


int main() {
    StaticLinkedList<int> list;
    
    list.push(1, 1);
    list.push(2, 2);
    list.push(88, 88);
    list.push(3, 3);
    list.push(4, 4);
    
    int a = 0;
    list.pull(a);
    std::cout << a << std::endl; 

    return 0;
}