#ifndef STACK_H
#define STACK_H

/// @brief Stack data structure 
typedef struct {
    int* list;
    int list_pointer;
    int size;
} Stack;

/// @brief Create a new stack
/// @param n Size of stack
/// @return Pointer to the created Stack
Stack* create(int n);

/// @brief Push data onto the stack
/// @param s Pointer to the stack
/// @param data Data to push
void push(Stack* s, int data);

/// @brief Pop data from the stack
/// @param s Pointer to the stack
/// @return Data popped from the stack
int pop(Stack* s);

/// @brief Get the top element of the stack without removing it
/// @param s Pointer to the stack
/// @return Top element of the stack
int top(Stack* s);

/// @brief Get the current size of the stack
/// @param s Pointer to the stack
/// @return Current size of the stack
int size(Stack* s);

/// @brief Check if the stack is empty
/// @param s Pointer to the stack
/// @return 1 if the stack is empty, 0 otherwise
int isEmpty(Stack* s);

/// @brief Release the memory allocated for the stack
/// @param s Pointer to the stack
void memory_release(Stack* s);

#endif
