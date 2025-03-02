# Linked Lists

## What is a Linked List?

A linked list is a linear data structure in which elements are stored in nodes, and each node points to the next node in the sequence. Unlike arrays, linked lists do not store elements in contiguous memory locations, allowing dynamic memory allocation and efficient insertions and deletions.

### Key Features:

- **Node Structure**: Each node contains two components:
  - **Data**: Holds the value or information.
  - **Pointer**: A reference to the next node (or previous node in some cases).
- **Dynamic Memory Allocation**: Memory is allocated as nodes are added, avoiding fixed-size limitations.
- **Non-contiguous Storage**: Nodes can be scattered in memory, connected through pointers.

## Types of Linked Lists

### 1. Singly Linked List

- Each node contains data and a pointer to the next node.
- Traversal is unidirectional — from the head node to the tail node.
- The last node points to `null`, marking the end of the list.

**Use case:** Implementing stacks and simple dynamic memory allocations.

### 2. Doubly Linked List

- Each node contains three components: data, a pointer to the next node, and a pointer to the previous node.
- Supports bidirectional traversal — both forward and backward.
- The first node’s previous pointer and the last node’s next pointer are set to `null`.

**Use case:** Useful for navigation systems (like web browser history) or undo mechanisms in applications.

### 3. Circular Linked List

- The last node points back to the first node, forming a circle.
- Can be:
  - **Singly Circular Linked List**: Only forward links, last node points to the first.
  - **Doubly Circular Linked List**: Nodes link both to their next and previous nodes, forming a closed loop.

**Use case:** Useful for real-time systems or processes with a continuous loop (like task scheduling in OS).

## Operations

### 1. **Traversal**

- Visiting each node sequentially.
- Time complexity: O(n)

### 2. **Insertion**

- Adding a node at the beginning, end, or a specific position.
- Time complexity: O(1) for head/tail insertion; O(n) for middle insertion.

### 3. **Deletion**

- Removing a node from the beginning, end, or a specific position.
- Time complexity: O(1) for head/tail deletion; O(n) for middle deletion.

### 4. **Searching**

- Finding a node containing specific data.
- Time complexity: O(n)

### 5. **Reversing**

- Changing the direction of a singly linked list.
- Time complexity: O(n)

## Advantages

- **Dynamic Size**: Grows or shrinks as needed without pre-allocating memory.
- **Efficient Insertions/Deletions**: No shifting of elements as in arrays — pointers are simply updated.
- **Memory Utilization**: Allocates memory only when needed, reducing wastage.
- **Ease of Implementation**: Useful for implementing abstract data types like stacks, queues, and graphs.

## Limitations

- **Sequential Access**: No direct access to elements — requires traversal from the head node.
- **Extra Memory Usage**: Each node requires additional memory for pointers.
- **Complexity**: Pointer management increases code complexity.
- **Cache Inefficiency**: Due to non-contiguous storage, linked lists have poor cache performance compared to arrays.
