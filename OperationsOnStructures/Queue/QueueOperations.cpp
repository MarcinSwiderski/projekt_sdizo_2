//
// Created by Marcin on 05.04.2021.
//

#include <chrono>
#include "../../Structures/Queue/Queue.h"
#include "QueueOperations.h"

using namespace std::chrono;
high_resolution_clock::time_point timeStartQueue;
high_resolution_clock::time_point timeStopQueue;

void queueCreate(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    timeStartQueue = high_resolution_clock::now();
    for (int i = 0; i < repeatsPerInstance; i++) {
        Queue *test_queue = createQueue(sizeOfStrucutre);
        for (int j = 0; j < sizeOfStrucutre; j++) {
            queueForward(test_queue, dataFromCsvVector[j]);
        }
    }
    timeStopQueue = high_resolution_clock::now();
    duration<double> finalDuration = duration_cast<duration<double>>(timeStartQueue - timeStopQueue);
    ResultByRow queueResult = ResultByRow("queue", "create", sizeOfStrucutre, finalDuration.count());
    results.push_back(queueResult.toString());
}

void queueSearch(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    srand(time(NULL));
    duration<double> finalDuration = duration<double>(0);
    for (int i = 0; i < repeatsPerInstance; i++) {
        Queue *testQueue = createQueue(sizeOfStrucutre);
        for (int j = 0; j < sizeOfStrucutre; j++) {
            queueForward(testQueue, dataFromCsvVector[j]);
        }
        int randomIndex = rand() % sizeOfStrucutre;
        int searchedValue = dataFromCsvVector[randomIndex];
        timeStartQueue = high_resolution_clock::now();
        Queue *tempQueue = createQueue(sizeOfStrucutre);
        int tempLength = 0;
        for (int k = 0; k < sizeOfStrucutre; k++) {
            if (checkFront(testQueue) == searchedValue) {
                break;
            } else {
                queueForward(tempQueue, queueBackwords(testQueue));
            }
            tempLength++;
        }
        for (int l = 0; l < tempLength; l++) {
            queueForward(testQueue, queueBackwords(tempQueue));
        }
        timeStopQueue = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(timeStopQueue - timeStartQueue);
    }
    ResultByRow queueResult = ResultByRow("queue", "search", sizeOfStrucutre, finalDuration.count());
    results.push_back(queueResult.toString());
}

void queueMovForward(int sizeOfStrucutre, unsigned repeatsPerInstance, vector<int> &dataFromCsvVector, vector<string> &results) {
    srand(time(NULL));
    duration<double> finalDuration = duration<double>(0);

    for (int i = 0; i < repeatsPerInstance; i++) {
        Queue *testQueue = createQueue(sizeOfStrucutre);
        for (int j = 0; j < sizeOfStrucutre; j++) {
            queueForward(testQueue, dataFromCsvVector[j]);
        }
        int randomValue = rand() % 1000000;
        timeStartQueue = high_resolution_clock::now();
        queueForward(testQueue, randomValue);
        timeStopQueue = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(timeStopQueue - timeStartQueue);
    }

    ResultByRow queueResult = ResultByRow("queue", "queueForward", sizeOfStrucutre, finalDuration.count());
    results.push_back(queueResult.toString());
}

void queueMovBackwords(int sizeOfStrucutre, unsigned numberOfRepeats, vector<int> &dataFromCsvVector, vector<string> &results) {
    duration<double> finalDuration = duration<double>(0);

    for (int i = 0; i < numberOfRepeats; i++) {
        Queue *test_queue = createQueue(sizeOfStrucutre);
        for (int j = 0; j < sizeOfStrucutre; j++) {
            queueForward(test_queue, dataFromCsvVector[j]);
        }
        timeStartQueue = high_resolution_clock::now();
        queueBackwords(test_queue);
        timeStopQueue = high_resolution_clock::now();
        finalDuration += duration_cast<duration<double>>(timeStopQueue - timeStartQueue);
    }
    ResultByRow queueResult = ResultByRow("queue", "queueBackwords", sizeOfStrucutre, finalDuration.count());
    results.push_back(queueResult.toString());
}