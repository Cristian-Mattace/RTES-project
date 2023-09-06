#ifndef QUEUELIB_CPP
#define QUEUELIB_CPP

#include "QueueLib.h"

#define NULL_PARAM -1

template <typename T, bool isStatic>
QueueLib<T, isStatic>::QueueLib(bool isVerbose) {
    queue.setVerbose(isVerbose);

    // semaphore turnstile initialization
    sem_unlink("/turnstile"); // if already exists
    turnstile = sem_open("/turnstile", O_CREAT | O_EXCL, 0666, 1);
    if(turnstile == SEM_FAILED)
        std::cout << "Error init of semaphore turnstile" << std::endl;

    // semaphore mutex initialization
    sem_unlink("/mutex"); // if already exists
    mutex = sem_open("/mutex", O_CREAT | O_EXCL, 0666, 1);
    if(mutex == SEM_FAILED)
        std::cout << "Error init of semaphore mutex" << std::endl;
}

template <typename T, bool isStatic>
QueueLib<T, isStatic>::~QueueLib() {
    // semaphore turnstile destruction
    sem_close(turnstile);
    sem_unlink("/turnstile"); // remove the semaphore
    // semaphore mutex destruction
    sem_close(mutex);
    sem_unlink("/mutex"); // remove the semaphore
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::push(const T& data, int param){
    sem_wait(turnstile);
    std::cout << "I'm inside" << std::endl;
    threadsWaiting++;
    if(threadsWaiting > 1){
        std::string semThreadName = "/semThread" + std::to_string(threadsWaiting);
        sem_unlink(semThreadName.c_str()); // if already exists
        sem_t* semThread = sem_open(semThreadName.c_str(), O_CREAT | O_EXCL, 0666, 1);
        if(mutex == SEM_FAILED)
            std::cout << "Error init of semaphore " << semThreadName << std::endl;
        semList.push(semThread);
        std::cout << "I'm going to wait" << std::endl;
        sem_post(turnstile);
        sem_wait(semList.getHead());
        sem_wait(turnstile);
        std::cout << "I'm awake" << std::endl;
    }
    sem_post(turnstile);

    sem_wait(mutex);
    queue.push(data, param);
    sem_post(mutex);

    sem_wait(turnstile);
    threadsWaiting--;
    if(threadsWaiting != 0){
        sem_t* semThread;
        semList.pull(semThread);
        sem_post(semThread);
        std::cout << "I woke up the first in line" << std::endl;
        sem_close(semThread);
        std::string semThreadName = "/semThread" + std::to_string(threadsWaiting);
        sem_unlink(semThreadName.c_str()); // remove the semaphore
    }
    sem_post(turnstile);
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::push(const T& idGroup){
    static_assert(!isStatic, "This method can be used only for DYNAMIC MODE!");
    queue.push(idGroup);
}

template <typename T, bool isStatic>
bool QueueLib<T, isStatic>::pull(T& data){
    return queue.pull(data);
}

template <typename T, bool isStatic>
bool QueueLib<T, isStatic>::pull(T& data, int idGroup){
    static_assert(!isStatic, "This method can be used only for DYNAMIC MODE!");
    return queue.pull(data, idGroup);
}

template <typename T, bool isStatic>
bool QueueLib<T, isStatic>::isEmpty() const {
    return queue.isEmpty();
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::toString() {
    queue.toString();
}

#endif