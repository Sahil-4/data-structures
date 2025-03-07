# Queue

## What is a Queue?

- A queue is a linear data structure where elements are added at one end (rear) and removed from the other end (front).
- It follows the **First In First Out (FIFO)** principle.

## Usage

- Commonly used in scenarios like process scheduling, job scheduling, and handling requests in buffers.

## Operations

- **Enqueue**: Adds an element to the rear.
- **Dequeue**: Removes an element from the front.
- **isEmpty**: Checks if the queue is empty.
- **isFull**: Checks if the queue is full (for fixed-size queues).
- **Size**: Returns the number of elements in the queue.

## Deque (Double-Ended Queue)

- A **deque** is a special type of queue where elements can be added or removed from both the front and rear.
- Types of Deques:
  - **Input-restricted deque**: Insertion is allowed only at the rear, but deletion can happen at both ends.
  - **Output-restricted deque**: Deletion is allowed only at the front, but insertion can happen at both ends.
- Useful for scenarios requiring both **FIFO** and **LIFO** operations, such as task scheduling or implementing undo mechanisms.

## Stack vs Queue

- A **stack** uses the **LIFO** principle (Last In First Out), while a **queue** uses **FIFO** (First In First Out).
- In a stack, both insertion (push) and deletion (pop) occur at the same end.
- In a queue, insertion (enqueue) happens at the rear, and deletion (dequeue) happens at the front.
- Stacks are ideal for backtracking or undo operations, whereas queues are suitable for scheduling and task processing.

## Advantages

- Maintains order, ensuring the first element added is processed first.
- Simple and efficient for sequential processing tasks.

## Limitations

- Searching for a specific element takes **O(N)** time in an unstructured queue, as elements must be checked sequentially.
