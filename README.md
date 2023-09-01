![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
# Static & Dynamic priority implementation with groups in C++

## Overview
The `init(MODE)` function allows the selection of either static or dynamic priority mode.
### Mode
- `Static Priority Mode`: in static mode, the system employs a singly linked list. Elements within this list are arranged in ascending order of priority.
- `Dynamic Priority Mode`: dynamic mode involves the utilization of groups, each identified by a static name assigned during group creation. These groups operate with dynamic priorities. Similarly to the static mode, the structure employed here is a singly linked list, where elements are arranged in a _first-in-first-out_ (**FIFO**) manner. To manage the ordering of groups by priority, a separate singly linked list is used. When groups are created, they are sorted by decreasing priority (the first group created will be the first, the second will be the second and so on).
![INIT](https://github.com/Cristian-Mattace/RTES-project/blob/main/resources/INIT.png)
### Functionality
- `push(PRIORITY)`: this function is used in both static and dynamic modes. The function inserts an element into the appropriate list according to the mode in use.
  - In **dynamic mode**, the priority parameter signifies the name of the group (an integer value).
- `pull()`: the pull() function is employed in both static and dynamic modes.
  - In **static mode**, it retrieves and removes the first element from the list.  
  - In **dynamic mode**, it retrieves and removes the first element from the highest-priority group. This action adjusts the group's position within the priority ordering list, effectively promoting the group to the forefront.
- `pull(GROUP)`: exclusive to dynamic mode, this function performs the same task as the basic pull() function but is also able to target a specific group. Upon retrieval of an element from the specified group, that group becomes the highest-priority group and is moved to the head of the priority ordering list.
<br><br>
For implementation details and usage examples, refer to the accompanying code documentation.
## Examples

