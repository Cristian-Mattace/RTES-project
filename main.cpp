#include <iostream>
#include "src/QueueLib.h"
#include <pthread.h>

QueueLib<int, true> queue(true);

void* threadFunction1(void* arg) {
    pthread_t tid = pthread_self();

    std::cout << "Thread " << tid << " in execution" << std::endl;

    //test dynamic
    //queue.push(1, 001);
    queue.push(1, 1, 001);
    int value = 0;
    queue.pull(value, 001);
    std::cout << value << std::endl;

    return NULL;
}

void* threadFunction2(void* arg) {
    pthread_t tid = pthread_self();

    std::cout << "Thread " << tid << " in execution" << std::endl;

    //test dynamic
    //queue.push(2, 002);
    queue.push(1, 2, 002);
    int value = 0;
    queue.pull(value, 002);
    std::cout << value << std::endl;

    return NULL;
}

void* threadFunction3(void* arg) {
    pthread_t tid = pthread_self();

    std::cout << "Thread " << tid << " in execution" << std::endl;

    //test dynamic
    //queue.push(3, 003);
    queue.push(1, 3, 003);
    int value = 0;
    queue.pull(value, 003);
    std::cout << value << std::endl;

    return NULL;
}

int main() {
    const int num_threads = 3;
    pthread_t threads[num_threads];

    int result = pthread_create(&threads[0], NULL, threadFunction1, NULL);
    if (result != 0) {
        std::cerr << "Threads creation error " << 0 << std::endl;
        return 1;
    }

    result = pthread_create(&threads[1], NULL, threadFunction2, NULL);
    if (result != 0) {
        std::cerr << "Threads creation error " << 1 << std::endl;
        return 1;
    }

    result = pthread_create(&threads[2], NULL, threadFunction3, NULL);
    if (result != 0) {
        std::cerr << "Threads creation error " << 2 << std::endl;
        return 1;
    }

    // wait threads termination
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    std::cout << "All threads terminated" << std::endl;

    return 0;
}