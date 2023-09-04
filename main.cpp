#include <iostream>
#include "src/singly-linked-list/StaticLinkedList.h"

int main() {
    StaticLinkedList<int> list;

    list.push(3, 3);
    list.toString();

    list.push(2, 2);
    list.toString();

    list.push(1, 1);
    list.toString();

    list.push(4, 4);
    list.toString();

    list.push(6, 6);
    list.toString();

    list.push(5, 5);
    list.toString();

    list.push(0, 0);
    list.toString();

    list.push(88, 5);
    list.toString();

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

    std::cout << list.isEmpty() << std::endl;
    return 0;
}