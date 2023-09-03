#ifndef SINGLYLINKEDLIST_CPP
#define SINGLYLINKEDLIST_CPP

#include "SinglyLinkedList.h"

// Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr) {}

// Destroyer
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::push(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if (!head) {
        newNode->next = nullptr;
        head = newNode;
    } 
    
    if(tail)
        tail->next = newNode;

    tail = newNode;
}

template <typename T>
bool SinglyLinkedList<T>::pull(T& data) {
    if (isEmpty())
        return false;

    Node<T>* temp = head;
    data = temp->data;
    head = head->next;
    delete temp;

    return true;
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::toString() {
    if(isEmpty())
        return;

    Node<T>* current = this->head;
    int i = 1;

    std::cout << "SinglyLinkedList: {";
    while (current->next){
        std::cout << "(" << i++ << ") data=[" << current->data << "]";
        current = current->next;
    }

    std::cout << "(" << i++ << ") data=[" << current->data << "]}";
}

#endif