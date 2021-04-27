//
// Created by Marcin on 22.03.2021.
//

#include <climits>
#include "Queue.h"

Queue::Queue(){

}
Queue *createQueue(unsigned int capacity) {
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}

int isQueueFull(Queue *queue) {
    return (queue->size == queue->capacity);
}

int isQueueEmpty(Queue *queue) {
    return (queue->size == 0);
}

void queueForward(Queue *queue, int item) {
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int queueBackwords(Queue *queue) {
    if (isQueueEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int checkFront(Queue *queue) {
    if (isQueueEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

Queue::~Queue() {
    delete[] array;
}