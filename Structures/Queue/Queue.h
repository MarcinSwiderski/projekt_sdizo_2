//
// Created by Marcin on 22.03.2021.
//

#ifndef UNTITLED_QUEUE_H
#define UNTITLED_QUEUE_H


class Queue {
public:
    Queue();
    int front, rear, size;
    unsigned int capacity;
    int *array;
    ~Queue();
};
Queue *createQueue(unsigned int capacity);

int isQueueFull(Queue *queue);

int isQueueEmpty(Queue *queue);

void queueForward(Queue *queue, int item);

int queueBackwords(Queue *queue);

int checkFront(Queue *queue);

#endif //UNTITLED_QUEUE_H
