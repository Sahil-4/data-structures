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
- **Time Complexity:** O(n)

### 2. **Insertion**

- Adding a node at the beginning, end, or a specific position.
- **Time Complexity:**
  - Head/Tail insertion: O(1)
  - Middle insertion: O(n)

### 3. **Deletion**

- Removing a node from the beginning, end, or a specific position.
- **Time Complexity:**
  - Head/Tail deletion: O(1)
  - Middle deletion: O(n)

### 4. **Searching**

- Finding a node containing specific data.
- **Time Complexity:** O(n)

### 5. **Reversing**

- Changing the direction of a singly linked list.
- **Time Complexity:** O(n)

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

## Algorithms

### **Insert at head**:

**Algorithm:**

1. Create a new node.
2. Set the new node's data to the given value.
3. Point the new node's next to the current head.
4. Update the head to the new node.

**Time Complexity:** O(1)

### **Insert at tail**:

**Algorithm:**

1. Create a new node.
2. Set the new node's data to the given value.
3. If the list is empty, set head to the new node.
4. Otherwise, traverse to the last node.
5. Set the last node's next to the new node.

**Time Complexity:** O(n) — traversal is required to reach the last node.

### **Insert at a specific position**:

**Algorithm:**

1. Create a new node.
2. Set the new node's data to the given value.
3. Traverse to the node before the target position.
4. Point the new node's next to the next node of the current node.
5. Set the current node's next to the new node.

**Time Complexity:** O(n)

### **Delete from head**:

**Algorithm:**

1. If the list is empty, return.
2. Update head to head's next node.
3. Free the memory of the previous head.

**Time Complexity:** O(1)

### **Delete from tail**:

**Algorithm:**

1. If the list is empty, return.
2. Traverse to the second last node.
3. Set the second last node's next to null.
4. Free the memory of the last node.

**Time Complexity:** O(n)

### **Delete from a specific position**:

**Algorithm:**

1. If the list is empty, return.
2. Traverse to the node before the target position.
3. Update the next pointer to skip the target node.
4. Free the memory of the target node.

**Time Complexity:** O(n)

### **Search an element**:

**Algorithm:**

1. Start from the head node.
2. Traverse each node while checking if the data matches the target value.
3. If found, return true.
4. If end of list is reached, return false.

**Time Complexity:** O(n)

### **Reverse a linked list**:

**Algorithm:**

1. Initialize three pointers: previous (null), current (head), and next (null).
2. Iterate through the list:
   - Set next to current's next.
   - Reverse current's next to point to previous.
   - Move previous and current one step forward.
3. Update head to previous.

**Time Complexity:** O(n)

### **Remove Duplicates from an Unsorted List**:

**Algorithm:**

1. Initialize current node as head.
2. For each node:
   - Use a runner node to check all subsequent nodes.
   - If a duplicate is found:
     - Update the next pointer to skip the duplicate node.
     - Free the duplicate node’s memory.
3. Move the current node to the next node.
4. Repeat until the end of the list.

**Time Complexity:** O(n²)

### **Find Middle Node**:

**Algorithm:**

1. Initialize two pointers: slow and fast.
2. Move slow by one step and fast by two steps.
3. When fast reaches the end (or null), slow will be at the middle node.
4. Return the slow pointer.

**Time Complexity:** O(n)

### **Merge Two Sorted Lists**:

**Algorithm:**

1. Create a new list for the merged result.
2. Initialize pointers for both lists at their heads.
3. Compare the current nodes of both lists:
   - Append the smaller node to the merged list.
   - Move the pointer of the list with the smaller node forward.
4. When one list is exhausted, append the remaining nodes from the other list.
5. Return the merged list.

**Time Complexity:** O(n + m) — n and m are the sizes of the two lists.

### **Detect Loop in a Linked List**:

**Algorithm:**

1. Initialize two pointers: slow and fast at the head.
2. Move slow by one step and fast by two steps.
3. If the two pointers meet, a loop exists.
4. If fast reaches null, no loop exists.

**Time Complexity:** O(n)
