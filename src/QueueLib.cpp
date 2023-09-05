#ifndef QUEUELIB_CPP
#define QUEUELIB_CPP

#include "QueueLib.h"

#define NULL_PARAM -1

template <typename T, bool isStatic>
QueueLib<T, isStatic>::QueueLib(bool isVerbose) {
    queue.setVerbose(isVerbose);
}

template <typename T, bool isStatic>
void QueueLib<T, isStatic>::push(const T& data, int param){
    if(param == NULL_PARAM)
        queue.push(data);
    else
        queue.push(data, param);
}

template <typename T, bool isStatic>
bool QueueLib<T, isStatic>::pull(T& data, int idGroup){
    if(idGroup == NULL_PARAM)
        return queue.pull(data);
    else
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