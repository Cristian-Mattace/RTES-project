#ifndef GROUPLINKEDLIST_CPP
#define GROUPLINKEDLIST_CPP

//#include "GroupsLinkedList.h"
//#include "SinglyLinkedList.h"

// Constructor
template <typename T>
GroupsLinkedList<T>::GroupsLinkedList(bool verbose) : head(nullptr), tail(nullptr), isVerbose(verbose){}

// Destroyer
template <typename T>
GroupsLinkedList<T>::~GroupsLinkedList() {

}

template <typename T>
void GroupsLinkedList<T>::push(const T& data, int idGroup) {
    GroupNode<SinglyLinkedList<T>>* current = head;

    //if there aren't group
    if(isEmpty())
      return;

    while (current->next && current->idGroup != idGroup)
        current = current->next;

    //if the current group is not the group searched
    if(current->idGroup != idGroup){
        std::cout << "IdGroup not found!" << std::endl;
        return;
    }

    current->data.push(data);

    if(isVerbose)
        toString();
}

template <typename T>
void GroupsLinkedList<T>::push(int idGroup) {
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
bool GroupsLinkedList<T>::pull(T& data) {
    if (isEmpty()){
        std::cout << "The list is empty!" << std::endl;
        return false;
    }

    GroupNode<SinglyLinkedList<T>>* current = this->head;
    
    while (current->next){
        if(!current->data.pull(data))
            current = current->next;
        else {
            if(isVerbose)
                toString();
            return true;
        }
    }

    // last element of the list
    if(!current->data.pull(data)){
        std::cout << "All groups are empty!" << std::endl;
        return false;
    }
    
    if(isVerbose)
        toString();
    
    return true;
}

template <typename T>
bool GroupsLinkedList<T>::pull(T& data, int idGroup) {
    if (isEmpty()){
        std::cout << "The list is empty!" << std::endl;
        return false;
    }

    GroupNode<SinglyLinkedList<T>>* current = this->head;
    GroupNode<SinglyLinkedList<T>>* previuos = nullptr;

    while (current->next && current->idGroup != idGroup){
        previuos = current;
        current = current->next;
    }
    
    if(current->idGroup != idGroup){
        std::cout << "IdGroup not found!" << std::endl;
        return false;
    }

    if(previuos != nullptr)
        previuos->next = current->next;

    GroupNode<SinglyLinkedList<T>>* newNode = head;
    head = current;
    head->next = newNode;

    pull(data);

    return true;
}


template <typename T>
bool GroupsLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void GroupsLinkedList<T>::toString() {
    if(isEmpty())
        return;

    GroupNode<SinglyLinkedList<T>>* current = this->head;

    std::cout << "GroupsLinkedList: ";
    while (current){
        std::cout << "(" << current->idGroup << ") data=[";
        current->data.toString();
        std::cout << "]";
        current = current->next;
    }

    std::cout << std::endl;
}

#endif