#ifndef NODE_H // checks if the identifier is not defined
#define NODE_H // defines the identifier, indicating that the header content should be included

#include <iostream>
#include <stdexcept>

template <typename T>

/**
* Node structure used inside SinglyLinkedList.
* @see SinglyLinkedList
*/
struct Node {
public:
    T data;
    Node* next;

    // Node constructor
    Node(const T& data);
};

template <typename T>
/**
* StaticNode structure, derived from Node structure, with the addition of priority.
* Used in static priority.
* @see StaticLinkedList
*/
struct StaticNode : public Node<T> {
public:
    int priority;
    StaticNode* next;

    // StaticNode constructor
    StaticNode(const T& data, int p);
};

template <typename T>
/**
* GroupNode structure, derived from Node structure, with the addition of group identifier.
* Used in dynamica priority.
* @see GroupLinkedList
*/
struct GroupNode : public Node<T> {
public:
    int idGroup;
    GroupNode* next;

    // GroupNode constructor
    GroupNode(const T& data, int idGroup);
};

// It's important to remember to include
#include "Node.cpp"

#endif