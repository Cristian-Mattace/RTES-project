#ifndef GROUPLINKEDLIST_H // checks if the identifier is not defined
#define GROUPLINKEDLIST_H // defines the identifier, indicating that the header content should be included

#include <iostream>
#include <stdexcept>
#include "node/Node.h"

template <typename T>

class GroupLinkedList {
private:
    GroupNode<SinglyLinkedList<T>>* head;
    GroupNode<SinglyLinkedList<T>>* tail;

public:
    // Constructor
    GroupLinkedList();

    // Destroyer
    ~GroupLinkedList();

    /**
     * Add new group into list.
     * @param idGroup it's the group identifier.
    */
    void push(int idGroup);

    /**
     * Add new value into group list.
     * @param data it's the value we want to insert in a specific group.
     * @param idGroup it's the group identifier.
    */
    void push(const T& data, int idGroup);

    /**
    * Remove the first data of the group with the highest priority.
    * @param data it's the value we want to extract.
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data);

    /**
    * Remove the first data of a specific group, which becomes the most priority.
    * @param data it's the value we want to extract.
    * @param idGroup it's the group identifier.
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data, int idGroup);
 
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
#include "GroupsLinkedList.cpp"

#endif // GROUPLINKEDLIST_H closes the block and provides a comment to indicate what it's closing