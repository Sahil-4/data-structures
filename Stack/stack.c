#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/// @brief Create a new stack
/// @param n Size of stack
/// @return Pointer to the created Stack
Stack* create(int n) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (!s) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    s->list = (int*)malloc(n * sizeof(int));
    if (!s->list) {
        fprintf(stderr, "Memory allocation failed\n");
        free(s);
        exit(1);
    }
    s->list_pointer = -1;
    s->size = n;
    return s;
}

/// @brief Push data onto the stack
/// @param s Pointer to the stack
/// @param data Data to push
void push(Stack* s, int data) {
    if (s->list_pointer == s->size - 1) {
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    s->list[++(s->list_pointer)] = data;
}

/// @brief Pop data from the stack
/// @param s Pointer to the stack
/// @return Data popped from the stack
int pop(Stack* s) {
    if (s->list_pointer == -1) {
        fprintf(stderr, "Stack underflow\n");
        return -1;
    }
    return s->list[(s->list_pointer)--];
}

/// @brief Get the top element of the stack without removing it
/// @param s Pointer to the stack
/// @return Top element of the stack
int top(Stack* s) {
    if (s->list_pointer == -1) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    return s->list[s->list_pointer];
}

/// @brief Get the current size of the stack
/// @param s Pointer to the stack
/// @return Current size of the stack
int size(Stack* s) {
    return s->list_pointer + 1;
}

/// @brief Check if the stack is empty
/// @param s Pointer to the stack
/// @return 1 if the stack is empty, 0 otherwise
int isEmpty(Stack* s) {
    return s->list_pointer == -1;
}

/// @brief Release the memory allocated for the stack
/// @param s Pointer to the stack
void memory_release(Stack* s) {
    if (s) {
        free(s->list);
        free(s);
    }
}
