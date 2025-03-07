#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

void push_front(Queue* queue, int item) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = item;
    newNode->next = queue->front;
    newNode->prev = NULL;

    if (isQueueEmpty(queue)) {
        queue->rear = newNode;
    }
    else {
        queue->front->prev = newNode;
    }

    queue->front = newNode;
    queue->size++;
}

void push_back(Queue* queue, int item) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = queue->rear;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
    }
    else {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->size++;
}

int pop_front(Queue* queue) {
    if (isQueueEmpty(queue)) return -1;

    QueueNode* temp = queue->front;
    int item = temp->data;

    queue->front = queue->front->next;
    if (queue->front) {
        queue->front->prev = NULL;
    }
    else {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return item;
}

int pop_back(Queue* queue) {
    if (isQueueEmpty(queue)) return -1;

    QueueNode* temp = queue->rear;
    int item = temp->data;

    queue->rear = queue->rear->prev;
    if (queue->rear) {
        queue->rear->next = NULL;
    }
    else {
        queue->front = NULL;
    }

    free(temp);
    queue->size--;
    return item;
}

int front(Queue* queue) {
    if (isQueueEmpty(queue)) return -1;
    return queue->front->data;
}

int back(Queue* queue) {
    if (isQueueEmpty(queue)) return -1;
    return queue->rear->data;
}

int isQueueEmpty(Queue* queue) {
    return (queue->size == 0);
}

void memory_release(Queue* queue) {
    QueueNode* current = queue->front;
    while (current != NULL) {
        QueueNode* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(queue);
}
