#ifndef QUEUE_H
#define QUEUE_H

/// @brief Queue Node 
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
    struct QueueNode* prev;
} QueueNode;

/// @brief Queue data structure 
typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

/// @brief Creates an empty queue.
/// @return A pointer to the newly created queue.
Queue* createQueue();

/// @brief Adds an item to the front of the queue.
/// @param queue A pointer to the queue.
/// @param item The item to be added to the queue.
void push_front(Queue* queue, int item);

/// @brief Adds an item to the back of the queue.
/// @param queue A pointer to the queue.
/// @param item The item to be added to the queue.
void push_back(Queue* queue, int item);

/// @brief Removes and returns the item from the start of the queue.
/// @param queue A pointer to the queue.
/// @return The item removed from the start of the queue.
int pop_front(Queue* queue);

/// @brief Removes and returns the item from the end of the queue.
/// @param queue A pointer to the queue.
/// @return The item removed from the end of the queue.
int pop_back(Queue* queue);

/// @brief Returns the front item of the queue without removing it.
/// @param queue A pointer to the queue.
/// @return The front item of the queue.
int front(Queue* queue);

/// @brief Returns the last item of the queue without removing it.
/// @param queue A pointer to the queue.
/// @return The last item of the queue.
int back(Queue* queue);

/// @brief Checks if the queue is empty.
/// @param queue A pointer to the queue.
/// @return 1 if the queue is empty, 0 otherwise.
int isQueueEmpty(Queue* queue);

/// @brief Frees the allocated memory for the queue.
/// @param queue A pointer to the queue.
void memory_release(Queue* queue);

#endif
