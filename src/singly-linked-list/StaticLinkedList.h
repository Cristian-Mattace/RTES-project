#ifndef STATICLINKEDLIST_H // checks if the identifier is not defined
#define STATICLINKEDLIST_H // defines the identifier, indicating that the header content should be included

#include <iostream>
#include <stdexcept>
#include "node/Node.h"

template <typename T>

class StaticLinkedList {
private:
    StaticNode<T>* head;
    bool isVerbose;

public:
    // Constructor
    StaticLinkedList(bool verbose = false);

    // Destroyer
    ~StaticLinkedList();

    /**
     * Add new value into list.
     * @param data it's the value we want to insert.
     * @param priority it's the element's priority.
    */
    void push(const T& data, int priority);

    /**
    * Remove the first data of the list.
    * @param data it's the value we want to extract.
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data);

    /**
    * Set isVerbose parameter
    * @param isVerbose
    */
    void setVerbose(bool isVerbose);

    /**
    * @return It returns true if the list is empty.
    */
    bool isEmpty() const;

    /**
    * List printing.
    */
    void toString();
};

// It's important to remember to include
#include "StaticLinkedList.cpp"

#endif // STATICLINKEDLIST_H closes the block and provides a comment to indicate what it's closing