![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
# Static & Dynamic priority implementation with groups in C++

## Overview
The `QueueLib<T, MODE>` function allows the selection of either static or dynamic priority mode.
### Mode
- `STATIC_MODE`: in static mode, the system employs a singly linked list. Elements within this list are arranged in descending order of priority.

- `DYNAMIC_MODE`: dynamic mode involves the utilization of groups, each identified by a static integer ID assigned during group creation. These groups operate with dynamic priorities. Similarly to the static mode, the structure employed here is a singly linked list, where elements are arranged in a _first-in-first-out_ (**FIFO**) manner. To manage the ordering of groups by priority, a separate singly linked list is used. When groups are created, they are sorted by decreasing priority (the first group created will be the first, the second will be the second and so on).
![INIT](https://github.com/Cristian-Mattace/RTES-project/blob/main/resources/INIT.png)
### Functionality STATIC_MODE
- `push(data, param)`: the function inserts an element into the correct position according to the priority (param). Data is the element we want to add.

- `pull(data)`: the function retrieves and removes the first element from the list, that is the element with most priority.

### Functionality DYNAMIC_MODE
- `push(idGroup)`: this function inserts a new group at the end of singly linked list.

- `push(data, param)`: the function inserts an element at the end of the specified group (param).

- `pull(data)`: it retrieves and removes the first element from the highest-priority group.

- `pull(data, idGroup)`: this function performs the same task as the basic pull() function but is also able to target a specific group. Upon retrieval of an element from the specified group, that group becomes the highest-priority group and is moved to the head of the priority ordering list.

In both functionalities, in all functions, there is a paramater (idThread) which indicates the specific thread that is using the queue.
<br><br>


For implementation details and usage examples, refer to the accompanying code documentation.

## Examples

### STATIC_MODE
```
// init the queue in static mode, with int items and verbose = true
QueueLib<int, STATIC_MODE> queue(true);

queue.push(1, 1, tid);
queue.push(3, 3, tid);
queue.push(2, 2, tid);

int value = 0;
queue.pull(value, tid);
std::cout << value << std::endl;

```
In output:

```
StaticLinkedList: {(1) data=[1]}
StaticLinkedList: {(1) data=[3](2) data=[1]}
StaticLinkedList: {(1) data=[3](2) data=[2](3) data=[1]}
StaticLinkedList: {(1) data=[2](2) data=[1]}
3
StaticLinkedList: {(1) data=[1]}
2
StaticLinkedList: {}
1
```
### DYNAMIC_MODE
```
// init the queue in dynamic mode, with int items and verbose = true
QueueLib<int, DYNAMIC_MODE> queue(true);

// creation group 1
queue.push(1, tid);
// adding values "11" and "12"
queue.push(11, 1, tid);
queue.push(12, 1, tid);

// creation group 2
queue.push(2, tid);
// adding values "21" and "22"
queue.push(21, 2, tid);
queue.push(22, 2, tid);

// creation group 3
queue.push(3, tid);
// adding values "31"
queue.push(31, 3, tid);

int value = 0;
queue.pull(value, tid);
std::cout << value << std::endl;
queue.pull(value, 3, tid);
std::cout << value << std::endl;
queue.pull(value, tid);
std::cout << value << std::endl;
queue.pull(value, 1, tid);
std::cout << value << std::endl;
queue.pull(value, tid);
std::cout << value << std::endl;
queue.pull(value, tid);
std::cout << value << std::endl;
```
In output:
```
GroupsLinkedList: {(1) data=[SinglyLinkedList: {(1) data=[11]}]}
GroupsLinkedList: {(1) data=[SinglyLinkedList: {(1) data=[11](2) data=[12]}]}

GroupsLinkedList: {(1) data=[SinglyLinkedList: {(1) data=[11](2) data=[12]}](2) data=[SinglyLinkedList: {(1) data=[21]}]}
GroupsLinkedList: {(1) data=[SinglyLinkedList: {(1) data=[11](2) data=[12]}](2) data=[SinglyLinkedList: {(1) data=[21](2) data=[22]}]}

GroupsLinkedList: {(1) data=[SinglyLinkedList: {(1) data=[11](2) data=[12]}](2) data=[SinglyLinkedList: {(1) data=[21](2) data=[22]}](3) data=[SinglyLinkedList: {(1) data=[31]}]}

GroupsLinkedList: {(1) data=[SinglyLinkedList: {(1) data=[12]}](2) data=[SinglyLinkedList: {(1) data=[21](2) data=[22]}](3) data=[SinglyLinkedList: {(1) data=[31]}]}
11

GroupsLinkedList: {(3) data=[SinglyLinkedList: {}](1) data=[SinglyLinkedList: {(1) data=[12]}](2) data=[SinglyLinkedList: {(1) data=[21](2) data=[22]}]}
31

GroupsLinkedList: {(3) data=[SinglyLinkedList: {}](1) data=[SinglyLinkedList: {}](2) data=[SinglyLinkedList: {(1) data=[21](2) data=[22]}]}
12

Group empty!
0

GroupsLinkedList: {(1) data=[SinglyLinkedList: {}](3) data=[SinglyLinkedList: {}](2) data=[SinglyLinkedList: {(1) data=[22]}]}
21

GroupsLinkedList: {(1) data=[SinglyLinkedList: {}](3) data=[SinglyLinkedList: {}](2) data=[SinglyLinkedList: {}]}
22

```



