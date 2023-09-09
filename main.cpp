#include <iostream>
#include "src/QueueLib.h"
#include <pthread.h>
#include <cstdint> // to include type uintptr_t
#include <cstdlib> // to include rand()
#include <unistd.h> // to include usleep()

QueueLib<int, DYNAMIC_MODE> queue(true);
//QueueLib<int, STATIC_MODE> queue(true);

int delayMicroseconds = rand() % 900000 + 100000; // random delay between 100ms and 1000ms


void* threadFunction1(void*) {
    uintptr_t tid = (uintptr_t) pthread_self();

    std::cout << "Thread " << (int)tid << " in execution" << std::endl;

    queue.push(1, tid);
    usleep(delayMicroseconds);
    queue.push(1, 1, tid);
    usleep(delayMicroseconds);
    queue.push(3, 1, tid);

    int value = 0;
    queue.pull(value, tid);
    std::cout << value << std::endl;
    queue.pull(value, tid);
    std::cout << value << std::endl;

    return NULL;
}

void* threadFunction2(void*) {
    uintptr_t tid = (uintptr_t) pthread_self();

    std::cout << "Thread " << (int)tid << " in execution" << std::endl;

    queue.push(2, tid);
    usleep(delayMicroseconds);
    queue.push(2, 2, tid);
    usleep(delayMicroseconds);
    queue.push(4, 2, tid);

    int value = 0;
    queue.pull(value, tid);
    std::cout << value << std::endl;
    queue.pull(value, tid);
    std::cout << value << std::endl;

    return NULL;
}

void* threadFunction3(void*) {
    uintptr_t tid = (uintptr_t) pthread_self();

    std::cout << "Thread " << (int)tid << " in execution" << std::endl;

    queue.push(3, tid);
    usleep(delayMicroseconds);
    queue.push(5, 3, tid);
    usleep(delayMicroseconds);
    queue.push(6, 3, tid);

    int value = 0;
    queue.pull(value, tid);
    std::cout << value << std::endl;
    queue.pull(value, tid);
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