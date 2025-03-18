#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(Heap* heap, int parent, int child) {
    if (heap->type == MIN_HEAP) {
        return heap->arr[parent] > heap->arr[child];
    }
        return heap->arr[parent] < heap->arr[child];
}

Heap* createHeap(int size, HeapType type) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));

    heap->arr = (int*)malloc(size * sizeof(int));
    heap->size = size;
    heap->count = 0;
    heap->type = type;

    return heap;
}

void heapifyUp(Heap* heap, int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && compare(heap, parent, index)) {
        swap(&heap->arr[parent], &heap->arr[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(Heap* heap, int index) {
    int leftChild, rightChild, target;

    while (index < heap->count) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        target = index;

        if (leftChild < heap->count && compare(heap, target, leftChild)) {
            target = leftChild;
        }

        if (rightChild < heap->count && compare(heap, target, rightChild)) {
            target = rightChild;
        }

        if (target == index) break;

        swap(&heap->arr[index], &heap->arr[target]);
        index = target;
    }
}

void insert(Heap* heap, int val) {
    if (heap->count >= heap->size) return;

    heap->arr[heap->count] = val;
    heap->count++;
    heapifyUp(heap, heap->count - 1);
}

int extract(Heap* heap) {
    if (heap->count <= 0) return -1;

    int top = heap->arr[0];

    swap(&heap->arr[0], &heap->arr[heap->count - 1]);
    heap->count--;

    heapifyDown(heap, 0);

    return top;
}

int peek(Heap* heap) {
    if (heap->count <= 0) return -1;
    return heap->arr[0];
}

void memory_release(Heap* heap) {
    if (!heap) return;
    free(heap->arr);
    free(heap);
}
