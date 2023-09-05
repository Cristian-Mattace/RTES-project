#include <iostream>
#include "src/QueueLib.h"
#include <pthread.h>

QueueLib<int, false> queue(true);

void* threadFunction1(void* arg) {
    pthread_t tid = pthread_self();

    std::cout << "Thread " << tid << " in exection" << std::endl;

    //test dynamic
    queue.push(1);
    queue.push(1, 1);
    int value = 0;
    queue.pull(value);
    std::cout << value << std::endl;

    return NULL;
}

void* threadFunction2(void* arg) {
    pthread_t tid = pthread_self();

    std::cout << "Thread " << tid << " in exection" << std::endl;

    //test dynamic
    queue.push(2);
    queue.push(1, 2);
    int value = 0;
    queue.pull(value);
    std::cout << value << std::endl;

    return NULL;
}

void* threadFunction3(void* arg) {
    pthread_t tid = pthread_self();

    std::cout << "Thread " << tid << " in exection" << std::endl;

    //test dynamic
    queue.push(3);
    queue.push(1, 3);
    int value = 0;
    queue.pull(value);
    std::cout << value << std::endl;

    return NULL;
}

int main() {
    const int num_threads = 3;
    pthread_t threads[num_threads];

    // thread creation
    /*for (int i = 0; i < num_threads; ++i) {
        int result = pthread_create(&threads[i], NULL, threadFunction, NULL);
        if (result != 0) {
            std::cerr << "Threads creation error " << i << std::endl;
            return 1;
        }
    }*/

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
