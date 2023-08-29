#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP

#include "SinglyLinkedList.h"

// Node constructor
template <typename T>
SinglyLinkedList<T>::Node::Node(const T& data, int p) : data(data), priority(p), next(nullptr) {}

// Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}

// Destroyer
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


template <typename T>
void SinglyLinkedList<T>::push(const T& data, int priority) {
    Node* newNode = new Node(data, priority);

    // if head not exists or my node priority is higher than node head priority
    if (!head || priority > head->priority) {
        newNode->next = head;
        head = newNode;
    } 
    else {
        Node* current = head;

        // if next node exists and its priority is equal or higher than my node priority
        while (current->next && priority <= current->next->priority)
            current = current->next;
        
        // add my node in right position
        newNode->next = current->next;
        current->next = newNode;
    }
}


template <typename T>
bool SinglyLinkedList<T>::pull(T& data) {
    if (isEmpty())
        return false;

    Node* temp = head;
    data = temp->data;
    head = head->next;
    delete temp;
    return true;
}


template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

#endif