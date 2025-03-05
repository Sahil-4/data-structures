# Stack

## What is a Stack?

- A stack is a linear data structure that is open at one end and follows the **Last In First Out (LIFO)** principle.
- A stack can hold a specific number of elements; adding more elements beyond its capacity results in a **stack overflow** error.
- An **underflow** occurs when trying to remove an element from an empty stack.

## Usage

- Stacks are useful in:
  - **Backtracking**: For example, solving mazes or puzzles.
  - **Recursion**: Stacks keep track of function calls, allowing nested functions to return in the correct order.

## Operations

- **push(element)**: Inserts an element into the stack — O(1).
- **pop()**: Removes the top element from the stack — O(1).
- **top() / peek()**: Returns the top element without removing it — O(1).
- **isEmpty()**: Checks if the stack is empty — O(1).
- **size()**: Returns the number of elements — O(1).

## Advantages

- **Easy to implement**: Simple logic with few operations.
- **Memory efficient**: Requires minimal extra space for pointers.
- **Constant access time (`O(1)`)**: Accessing the top element is fast and direct.

## Limitations

- **Fixed size**: Static stacks have a predetermined size, leading to potential overflow if the capacity is exceeded. Dynamic stacks (like in most programming languages) can grow as needed.
- **Limited use cases**: Best suited for scenarios requiring reverse-order access, like recursion or backtracking.
- **LIFO nature**: Access is restricted to the top element only — you cannot directly access elements deeper in the stack.
