#ifndef QUEUELIB_H // checks if the identifier is not defined
#define QUEUELIB_H // defines the identifier, indicating that the header content should be included

#include <iostream>
#include <stdexcept>
#include "singly-linked-list/StaticLinkedList.h"
#include "singly-linked-list/GroupsLinkedList.h"

template <typename T, bool isStatic = true>

class QueueLib {
private:
    typename std::conditional<isStatic, StaticLinkedList<T>, GroupsLinkedList<T>>::type queue;

public:
    QueueLib(bool isVerbose = false);

    /**
    * Add new value into list if the parameter param was passed.
    * If param = -1, then the push will create a new queue group because we are running in dynamic priority.
    * @param data it's the value we want to insert.
    * @param param the parameter, which can be one of the following:
    *   - static priority: it's the priority.
    *   - dynamic priority: insert into a specific dynamic list (idGroup).
    */
    void push(const T& data, int param = -1);

    /**
    * Remove the first data of the list (static priority) or, if idGroup = -1, then remove the first data of the first group (dynamic priority).
    * @param data it's the value we want to extract.
    * @param idGroup the pull will remove the first element of a specific dynamic group (idGroup)
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data, int idGroup = -1);


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
#include "QueueLib.cpp"

#endif // QUEUELIB_H closes the block and provides a comment to indicate what it's closing