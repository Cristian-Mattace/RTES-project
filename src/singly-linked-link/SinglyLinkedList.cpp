#include <SinglyLinkedList.h>

// Node constructor
template <typename T>
SinglyLinkedList<T>::Node::Node(const T& data, int p) : data(data), priority(p), next(nullptr) {}

// Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr) {}


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