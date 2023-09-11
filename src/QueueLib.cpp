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
    if(turnstile == SEM_FAILED){
        std::cerr << "Error init of semaphore turnstile" << std::endl;
        exit(EXIT_FAILURE);
    }

    // semaphore mutex initialization
    sem_unlink("/mutex"); // if already exists
    mutex = sem_open("/mutex", O_CREAT | O_EXCL, 0666, 1);
    if(mutex == SEM_FAILED){
        std::cerr << "Error init of semaphore mutex" << std::endl;
        sem_close(turnstile);
        sem_unlink("/turnstile");
        exit(EXIT_FAILURE);
    }
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
void QueueLib<T, isStatic>::getMutex(int idThread){

    sem_wait(turnstile);
    if(queue.getVerbose())
        std::cout << idThread << " -> I'm inside turnstile" << std::endl;
    threadsWaiting++;

    if(threadsWaiting > 1){
        std::string semThreadName = "/semThread" + std::to_string(threadsWaiting);
        sem_unlink(semThreadName.c_str()); // if already exists
        sem_t* semThread = sem_open(semThreadName.c_str(), O_CREAT | O_EXCL, 0666, 0);

        if(semThread == SEM_FAILED){
            std::cerr << idThread <<  " -> Error init of semaphore " << semThreadName << std::endl;
            exit(EXIT_FAILURE);
        }
        
        // add semThread to singly linked list
        semList.push(semThread);

        if(queue.getVerbose())
            std::cout << idThread << " -> I'm going to wait" << std::endl;
        
        // release the turnstile 
        sem_post(turnstile);
        // wait on the semThread of this thread
        sem_wait(semThread);

        if(queue.getVerbose())
            std::cout << idThread <<  " -> I'm awake" << std::endl;
    }
    
    // release the turnstile (TOKEN PASSING)
    sem_post(turnstile);
    
    // get the mutex
    sem_wait(mutex);
    if(queue.getVerbose())
        std::cout << idThread << " -> I'm inside" << std::endl;
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::releaseMutex(int idThread){
    if(queue.getVerbose())
        std::cout << idThread << " -> I'm going to release the MUTEX" << std::endl;
    
    // release the mutex
    sem_post(mutex);

    sem_wait(turnstile);
    threadsWaiting--;
    
    if(threadsWaiting > 0){
        sem_t* semThread;
        // semThread will be the head semaphore
        semList.pull(semThread);
        // awake first thread in queue WITH the turnstile (TOKEN PASSING)
        sem_post(semThread);

        if(queue.getVerbose())
            std::cout << idThread << " -> I woke up the first in line" << std::endl;
        
        sem_close(semThread);
        std::string semThreadName = "/semThread" + std::to_string(threadsWaiting);
        sem_unlink(semThreadName.c_str()); // remove the semaphore
    } else
        sem_post(turnstile);
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::push(const T& data, int param, int idThread){
    getMutex(idThread);
    queue.push(data, param);
    releaseMutex(idThread);
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::push(const T& idGroup, int idThread){
    static_assert(!isStatic, "This method can be used only for DYNAMIC MODE!");

    getMutex(idThread);
    queue.push(idGroup);
    releaseMutex(idThread);
}

template <typename T, bool isStatic>
bool QueueLib<T, isStatic>::pull(T& data, int idThread){

    getMutex(idThread);
    bool result = queue.pull(data);
    releaseMutex(idThread);
    return result;
}

template <typename T, bool isStatic>
bool QueueLib<T, isStatic>::pull(T& data, int idGroup, int idThread){
    static_assert(!isStatic, "This method can be used only for DYNAMIC MODE!");

    getMutex(idThread);
    bool result = queue.pull(data, idGroup);
    releaseMutex(idThread);
    return result;
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