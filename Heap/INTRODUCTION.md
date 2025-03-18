# Heap

## What is Heap?

- a complete binary tree data structure
- it satisfies the heap property (child node value depends on parent)

## Types of Heap

- **min heap**: child node's value is always greater then parent node.
- **max heap**: child node's value is always smaller then parent node.

## Usage

- commonly used to implement priority queues.
- implement heapsort (sorting algorithm).
- used in graph algorithms like Dijkstra’s algorithm and Prim’s algorithm for finding the shortest paths and minimum spanning trees.

## Operations

- **Insert** : Add new element in heap.
- **Extract** : Removes the top most element from the heap and returns it.
- **Heapify** : Converts an arbitrary binary tree into a heap.

## Advantages

- **Access min/max element in O(1)**
- **Access elements in sorted form**

## Limitations

- **No direct access to elements other then top most**
- **Insertion/Deletion may take log(n)**
