#ifndef HEAP_H
#define HEAP_H

typedef enum {
    MIN_HEAP,
    MAX_HEAP
} HeapType;

typedef struct {
    int* arr;
    int size;
    int count;
    HeapType type;
} Heap;

Heap* createHeap(int size, HeapType type);

void insert(Heap* heap, int val);

int extract(Heap* heap);

int peek(Heap* heap);

void heapifyUp(Heap* heap, int index);

void heapifyDown(Heap* heap, int index);

int compare(Heap* heap, int parent, int child);

void memory_release(Heap* heap);

#endif
