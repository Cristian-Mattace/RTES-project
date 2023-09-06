#include <iostream>
#include "src/singly-linked-list/SinglyLinkedList.h"
#include "src/singly-linked-list/GroupsLinkedList.h"

int main() {
    GroupsLinkedList<int> groupsList;

    int value = 0;
    groupsList.push(1);
    groupsList.push(11, 1);

    groupsList.pull(value);
    std::cout << value << std::endl;

    groupsList.push(21, 1);

    groupsList.push(2);
    groupsList.push(12, 2);

    groupsList.pull(value, 2);
    std::cout << value << std::endl;

    groupsList.push(22, 2);

    groupsList.pull(value);
    std::cout << value << std::endl;

    groupsList.pull(value);
    std::cout << value << std::endl;

    groupsList.pull(value);
    std::cout << value << std::endl;

    return 0;
}