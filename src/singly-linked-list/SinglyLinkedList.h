#ifndef SINGLYLINKEDLIST_H // checks if the identifier is not defined
#define SINGLYLINKEDLIST_H // defines the identifier, indicating that the header content should be included

#include <iostream>
#include <stdexcept>
#include "node/Node.h"

template <typename T>

class SinglyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    // Constructor
    SinglyLinkedList();

    // Destroyer
    ~SinglyLinkedList();

    /**
     * Add new value at the end of the list.
     * @param data it's the value we want to insert.
    */
    void push(const T& data);

    /**
    * Remove the first data of the list.
    * @param data it's the value we want to extract.
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data);


    /**
    * @return It returns true if the list is empty.
    */
    bool isEmpty() const;

    /**
    * List printing.
    */
    void toString();

    /**
    * @return It retuns the head element.
    */
    T getHead();
};

// It's important to remember to include
#include "SinglyLinkedList.cpp"

#endif // SINGLYLINKEDLIST_H closes the block and provides a comment to indicate what it's closing