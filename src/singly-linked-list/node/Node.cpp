#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

// Node constructor
template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr) {}

// StaticNode constructor
template <typename T>
StaticNode<T>::StaticNode(const T& data, int priority) : Node<T>(data), priority(priority) {}

// GroupNode constructor
template <typename T>
GroupNode<T>::GroupNode(const T& data, int idGroup) : Node<T>(data), idGroup(idGroup) {}

#endif