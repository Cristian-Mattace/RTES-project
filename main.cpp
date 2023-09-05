#include <iostream>
#include "src/singly-linked-list/SinglyLinkedList.h"
#include "src/singly-linked-list/GroupsLinkedList.h"

int main() {
    GroupsLinkedList<int> groupsList;

    groupsList.push(1);
    groupsList.push(11, 1);
    groupsList.push(21, 1);

    groupsList.push(2);
    groupsList.push(12, 2);
    groupsList.push(22, 2);

    groupsList.push(3);
    groupsList.push(13, 3);
    groupsList.push(23, 3);

    groupsList.push(4);
    groupsList.push(14, 4);
    groupsList.push(24, 4);

    std::cout << std::endl;
    std::cout << std::endl;

    int value = 0;
    groupsList.pull(value, 2);
    std::cout << value << std::endl;

    groupsList.pull(value, 4);
    std::cout << value << std::endl;

    groupsList.pull(value, 3);
    std::cout << value << std::endl;

    groupsList.pull(value, 1);
    std::cout << value << std::endl;

    groupsList.pull(value);
    std::cout << value << std::endl;

    groupsList.pull(value);
    std::cout << value << std::endl;

    groupsList.pull(value);
    std::cout << value << std::endl;

    groupsList.pull(value);
    std::cout << value << std::endl;

    groupsList.pull(value);
    std::cout << value << std::endl;

    return 0;
}
