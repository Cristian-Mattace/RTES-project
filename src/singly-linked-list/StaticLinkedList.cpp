#ifndef STATICLINKEDLIST_CPP
#define STATICLINKEDLIST_CPP

#include "StaticLinkedList.h"

// Constructor
template <typename T>
StaticLinkedList<T>::StaticLinkedList(bool verbose) : head(nullptr), isVerbose(verbose){}

// Destroyer
template <typename T>
StaticLinkedList<T>::~StaticLinkedList() {
    while (head) {
        StaticNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void StaticLinkedList<T>::push(const T& data, int priority) {
    StaticNode<T>* current = this->head;
    StaticNode<T>* previous = nullptr;

    // Traverse the list to find the appropriate position to insert the new node
    while (current && priority <= current->priority) {
        previous = current;
        current = current->next;
    }

    // Create the new node
    StaticNode<T>* newNode = new StaticNode<T>(data, priority);

    if (!previous) {
        // Insert at the beginning of the list
        newNode->next = this->head;
        this->head = newNode;
    } else {
        // Insert after previous
        newNode->next = previous->next;
        previous->next = newNode;
    }

    if(isVerbose)
        toString();
}

template <typename T>
bool StaticLinkedList<T>::pull(T& data) {
    if (isEmpty()){
        std::cout << "The list is empty!" << std::endl;
        data = 0;
        return false;
    }
        
    StaticNode<T>* temp = head;
    data = temp->data;
    head = head->next;
    delete temp;

    if(isVerbose)
        toString();

    return true;
}

template <typename T>
void StaticLinkedList<T>::setVerbose(bool isVerbose) {
    this->isVerbose = isVerbose;
}

template <typename T>
bool StaticLinkedList<T>::getVerbose() {
    return isVerbose;
}

template <typename T>
bool StaticLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void StaticLinkedList<T>::toString() {
    StaticNode<T>* current = this->head;
    int i = 1;

    std::cout << "StaticLinkedList: {";
    while (current){
        std::cout << "(" << i++ << ") data=[" << current->data << "]";
        current = current->next;
    }

    std::cout << "}" << std::endl;
}

#endif