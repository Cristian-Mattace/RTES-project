#ifndef QUEUELIB_H // checks if the identifier is not defined
#define QUEUELIB_H // defines the identifier, indicating that the header content should be included

#include <iostream>
#include <stdexcept>
#include <semaphore.h>
#include "singly-linked-list/StaticLinkedList.h"
#include "singly-linked-list/GroupsLinkedList.h"

template <typename T, bool isStatic = true>

class QueueLib {
private:
    typename std::conditional<isStatic, StaticLinkedList<T>, GroupsLinkedList<T>>::type queue;
    sem_t* mutex;

    /**
    * Takes the mutex, if not available queues on the turnstile semaphore.
    * @param idThread it's the thread ID.
    */
    void getMutex(int idThread);

    /**
    * Release the mutex and make a post on the turnstile semaphore.
    * @param idThread it's the thread ID.
    */
    void releaseMutex(int idThread);

public:
    // Constructor 
    QueueLib(bool isVerbose = false);

    // Destroyer
    ~QueueLib();

    /**
    * Add new value into list if the parameter param was passed.
    * @param data it's the value we want to insert.
    * @param param the parameter, which can be one of the following:
    *   - static priority: it's the priority.
    *   - dynamic priority: insert into a specific dynamic list (idGroup).
    * @param idThread it's the thread ID.
    */
    void push(const T& data, int param, int idThread);

    /**
    * Add new group into list (DYNAMIC PRIORITY).
    * @param idGroup it's the group identifier we want to insert.
    * @param idThread it's the thread ID.
    */
    void push(const T& idGroup, int idThread);

    /**
    * The pull will remove the first element of a specific dynamic group (idGroup) and and the specified group becomes the highest priority (DYNAMIC PRIORITY).
    * @param data it's the value we want to extract.
    * @param idGroup the pull will remove the first element of a specific dynamic group (idGroup).
    * @param idThread it's the thread ID.
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data, int idGroup, int idThread);

    /**
    * Remove the first data of the list (STATIC PRIORITY) or it removes the first data of the first group (DYNAMIC PRIORITY).
    * @param data it's the value we want to extract.
    * @param idThread it's the thread ID.
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data, int idThread);

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