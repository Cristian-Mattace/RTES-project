#include <iostream>
#include "src/QueueLib.h"

int main() {
    QueueLib<int, false> queue(true);

    //test dynamic
    queue.push(1);
    queue.push(1, 1);
    int value = 0;
    queue.pull(value);
    std::cout << value << std::endl;

    return 0;
}
