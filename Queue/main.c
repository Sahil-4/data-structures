#include <stdio.h>
#include <assert.h>
#include "queue.h"

void test() {
    // Create a queue
    Queue* queue = createQueue();
    assert(queue != NULL);
    assert(isQueueEmpty(queue) == 1);

    // Add elements at front
    push_front(queue, 10);
    assert(front(queue) == 10);
    assert(back(queue) == 10);
    assert(isQueueEmpty(queue) == 0);

    push_front(queue, 20);
    assert(front(queue) == 20);
    assert(back(queue) == 10);
    assert(queue->size == 2);

    // Test adding elements at back
    push_back(queue, 30);
    assert(front(queue) == 20);
    assert(back(queue) == 30);
    assert(queue->size == 3);

    push_back(queue, 40);
    assert(front(queue) == 20);
    assert(back(queue) == 40);
    assert(queue->size == 4);

    // Remove elements from front
    int removed = pop_front(queue);
    assert(removed == 20);
    assert(front(queue) == 10);
    assert(back(queue) == 40);
    assert(queue->size == 3);

    removed = pop_front(queue);
    assert(removed == 10);
    assert(front(queue) == 30);
    assert(back(queue) == 40);
    assert(queue->size == 2);

    // Remove elements from back
    removed = pop_back(queue);
    assert(removed == 40);
    assert(front(queue) == 30);
    assert(back(queue) == 30);
    assert(queue->size == 1);

    removed = pop_back(queue);
    assert(removed == 30);
    assert(isQueueEmpty(queue) == 1);
    assert(queue->size == 0);

    // Edge case: pop from empty queue
    removed = pop_front(queue);
    assert(removed == -1);

    removed = pop_back(queue);
    assert(removed == -1);

    // Single element add/remove test
    push_back(queue, 50);
    assert(front(queue) == 50);
    assert(back(queue) == 50);
    assert(queue->size == 1);

    removed = pop_front(queue);
    assert(removed == 50);
    assert(isQueueEmpty(queue) == 1);

    // Alternating push/pop test
    push_front(queue, 5);
    push_back(queue, 15);
    removed = pop_back(queue);
    assert(removed == 15);
    removed = pop_front(queue);
    assert(removed == 5);
    assert(isQueueEmpty(queue) == 1);

    // Stress test: add and remove many elements
    for (int i = 0; i < 1000; i++) {
        push_back(queue, i);
    }
    assert(queue->size == 1000);

    for (int i = 0; i < 1000; i++) {
        pop_front(queue);
    }
    assert(isQueueEmpty(queue) == 1);

    // Test memory release on non-empty queue
    push_back(queue, 100);
    push_back(queue, 200);
    memory_release(queue);

    printf("All tests passed!\n");
}

int main() {
    // Test Queue data structure
    test();

    return 0;
}
