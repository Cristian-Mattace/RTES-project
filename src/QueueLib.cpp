#ifndef QUEUELIB_CPP
#define QUEUELIB_CPP

#include "QueueLib.h"

#define NULL_PARAM -1

template <typename T, bool isStatic>
QueueLib<T, isStatic>::QueueLib(bool isVerbose) {
    queue.setVerbose(isVerbose);

    // semaphore mutex initialization
    sem_unlink("/mutex"); // if already exists
    mutex = sem_open("/mutex", O_CREAT | O_EXCL, 0666, 1);
    if(mutex == SEM_FAILED)
        std::cout << "Error init of semaphore mutex" << std::endl;
}

template <typename T, bool isStatic>
QueueLib<T, isStatic>::~QueueLib() {
    // semaphore mutex destruction
    sem_close(mutex);
    sem_unlink("/mutex"); // remove the semaphore
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::getMutex(int idThread){
    sem_wait(mutex);
    if(queue.getVerbose())
        std::cout << idThread << " -> I'm inside" << std::endl;
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::releaseMutex(int idThread){
    if(queue.getVerbose())
        std::cout << idThread << " -> I'm going to release the MUTEX" << std::endl;
    sem_post(mutex);
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