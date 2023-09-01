#ifndef STATICLINKEDLIST_CPP
#define STATICLINKEDLIST_CPP

#include "StaticLinkedList.h"

// Constructor
template <typename T>
StaticLinkedList<T>::StaticLinkedList() : head(nullptr){}

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
    StaticNode<T>* newNode = new StaticNode<T>(data, priority);

    // if head not exists or my node priority is higher than node head priority
    if (!this->head || priority > this->head->priority) {
        newNode->next = this->head;
        this->head = newNode;
    } 
    else {
        StaticNode<T>* current = this->head;

        // if next node exists and its priority is equal or higher than my node priority
        while (current->next && priority <= current->priority)
            current = current->next;
        
        // add my node in right position
        newNode->next = current->next;
        current->next = newNode;
    }
}

template <typename T>
bool StaticLinkedList<T>::pull(T& data) {
    if (isEmpty())
        return false;

    StaticNode<T>* temp = head;
    data = temp->data;
    head = head->next;
    delete temp;
    return true;
}

template <typename T>
bool StaticLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void StaticLinkedList<T>::toString() {
    if(isEmpty())
        return;

    StaticNode<T>* current = this->head;
    int i = 1;

    std::cout << "StaticLinkedList: {";
    while (current->next){
        std::cout << "(" << i++ << ") data=[" << current->data << "]";
        current = current->next;
    }

    std::cout << "(" << i++ << ") data=[" << current->data << "]}" << std::endl;
}

#endif