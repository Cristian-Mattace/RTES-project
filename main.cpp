#include <iostream>
#include "src/singly-linked-list/StaticLinkedList.h"

int main() {
    StaticLinkedList<int> list;

    list.push(3, 3);
    list.push(2, 2);
    list.push(1, 1);
    list.push(4, 4);
    list.push(6, 6);
    list.push(5, 5);
    list.push(129, 0);
    list.push(88, 5);

    int a = 0;
    list.pull(a);
    std::cout << a << std::endl;

    list.pull(a);
    std::cout << a << std::endl;

    list.pull(a);
    std::cout << a << std::endl;

    list.pull(a);
    std::cout << a << std::endl;

    list.pull(a);
    std::cout << a << std::endl;

    list.pull(a);
    std::cout << a << std::endl;

    list.pull(a);
    std::cout << a << std::endl;

    list.pull(a);
    std::cout << a << std::endl;

    std::cout << "List is empty? " << list.isEmpty() << std::endl;
    return 0;
}