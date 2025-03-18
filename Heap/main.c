#include <stdio.h>
#include <assert.h>
#include "heap.h"

void testMinHeap() {
    printf("Testing Min-Heap...\n");

    Heap* minHeap = createHeap(10, MIN_HEAP);

    // Test insert
    insert(minHeap, 5);
    insert(minHeap, 3);
    insert(minHeap, 8);
    insert(minHeap, 1);
    insert(minHeap, 9);

    // Test peek
    assert(peek(minHeap) == 1); // 1 should be the smallest element

    // Test extract
    assert(extract(minHeap) == 1); // Remove 1
    assert(peek(minHeap) == 3);    // Now 3 should be the smallest
    assert(extract(minHeap) == 3); // Remove 3
    assert(extract(minHeap) == 5); // Remove 5

    // Test insert again after extraction
    insert(minHeap, 2);
    assert(peek(minHeap) == 2);

    // Test extract for all remaining elements
    assert(extract(minHeap) == 2);
    assert(extract(minHeap) == 8);
    assert(extract(minHeap) == 9);

    // Heap should now be empty
    assert(peek(minHeap) == -1);
    assert(extract(minHeap) == -1);

    printf("Min-Heap tests passed.\n");

    memory_release(minHeap);
}

void testMaxHeap() {
    printf("Testing Max-Heap...\n");

    Heap* maxHeap = createHeap(10, MAX_HEAP);

    // Test insert
    insert(maxHeap, 5);
    insert(maxHeap, 3);
    insert(maxHeap, 8);
    insert(maxHeap, 1);
    insert(maxHeap, 9);

    // Test peek
    assert(peek(maxHeap) == 9); // 9 should be the largest element

    // Test extract
    assert(extract(maxHeap) == 9); // Remove 9
    assert(peek(maxHeap) == 8);    // Now 8 should be the largest
    assert(extract(maxHeap) == 8); // Remove 8
    assert(extract(maxHeap) == 5); // Remove 5

    // Test insert again after extraction
    insert(maxHeap, 7);
    assert(peek(maxHeap) == 7);

    // Test extract for all remaining elements
    assert(extract(maxHeap) == 7);
    assert(extract(maxHeap) == 3);
    assert(extract(maxHeap) == 1);

    // Heap should now be empty
    assert(peek(maxHeap) == -1);
    assert(extract(maxHeap) == -1);

    printf("Max-Heap tests passed.\n");

    memory_release(maxHeap);
}

void test() {
    testMinHeap();
    testMaxHeap();

    printf("All tests passed.\n");
}

int main() {
    test();

    return 0;
}
