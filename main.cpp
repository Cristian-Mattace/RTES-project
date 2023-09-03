#include <iostream>
#include "src/singly-linked-list/SinglyLinkedList.h"

int main() {
    SinglyLinkedList<int> list;

    list.push(3);
    list.push(2);

    int a = 0;
    list.pull(a);
    std::cout << a << std::endl;
    return 0;
}
