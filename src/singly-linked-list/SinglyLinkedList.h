#include <iostream>
#include <stdexcept>

template <typename T>

class SinglyLinkedList {
private:
    // Node inside singly linked list 
    struct Node {
        T data;
        int priority;
        Node* next;

        // Node constructor
        Node(const T& data, int p) : data(data), priority(p), next(nullptr) {}
    };

    Node* head;

public:
    // Constructor
    SinglyLinkedList();

    // Destroyer
    ~SinglyLinkedList();


    /**
     * Add new value into list.
     * @param data it's the value we want to insert.
     * @param priority it's the element's priority.
    */
    void push(const T& data, int priority);

    /**
    * Remove the first data of the list.
    * @param data it's the value we want to extract.
    * @return returns true if the method returned the first element of the list.
    */
    bool pull(T& data);


    /**
    * @return It returns true if the list is empty.
    */
    bool isEmpty() const;

};
