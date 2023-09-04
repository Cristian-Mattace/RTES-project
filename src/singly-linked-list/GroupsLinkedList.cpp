#ifndef GROUPLINKEDLIST_CPP
#define GROUPLINKEDLIST_CPP

//#include "GroupsLinkedList.h"
//#include "SinglyLinkedList.h"

// Constructor
template <typename T>
GroupLinkedList<T>::GroupLinkedList() : head(nullptr), tail(nullptr){}

// Destroyer
template <typename T>
GroupLinkedList<T>::~GroupLinkedList() {
    while (head) {
        GroupNode<SinglyLinkedList<T>>* temp = head;
        head = head->next;
        delete temp;
    }

    tail = nullptr;
}

template <typename T>
void GroupLinkedList<T>::push(int idGroup) {
    GroupNode<SinglyLinkedList<T>>* newNode = new GroupNode<SinglyLinkedList<T>>(SinglyLinkedList<T>(), idGroup);

    if (!head) {
        newNode->next = nullptr;
        head = newNode;
    } 
    
    if(tail)
        tail->next = newNode;

    tail = newNode;
}

template <typename T>
bool GroupLinkedList<T>::pull(T& data) {
    if (isEmpty()){
        std::cout << "The list is empty!" << std::endl;
        return false;
    }

    GroupNode<SinglyLinkedList<T>>* current = this->head;
    
    while (current->next){
        if(!current->data.pull(data))
            current = current->next;
        else {
            toString();
            return true;
        }
    }

    // last element of the list
    if(!current->data.pull(data)){
        std::cout << "All groups are empty!" << std::endl;
        return false;
    }

    toString();
    return true;
    
}


template <typename T>
bool GroupLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void GroupLinkedList<T>::toString() {
    if(isEmpty())
        return;

    GroupNode<SinglyLinkedList<T>>* current = this->head;

    std::cout << "GroupLinkedList: ";
    while (current->next){
        std::cout << "(" << current->idGroup << ") data=[";
        current->data.toString();
        std::cout << "]";
        current = current->next;
    }

    std::cout << "(" << current->idGroup << ") data=[";
    current->data.toString();
    std::cout << "]" << std::endl;
}

#endif