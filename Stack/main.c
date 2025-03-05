#include <stdio.h>
#include <assert.h>
#include "stack.h"

void test_stack() {
    // Creating instance of Stack 
    Stack* myStack = create(5);

    // Test isEmpty on a new stack
    assert(isEmpty(myStack) == 1);

    // Test push
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    // Test top
    assert(top(myStack) == 30);

    // Test size
    assert(size(myStack) == 3);

    // Test pop
    assert(pop(myStack) == 30);
    assert(pop(myStack) == 20);
    assert(pop(myStack) == 10);

    // Test isEmpty after popping all elements
    assert(isEmpty(myStack) == 1);

    // Test pop on an empty stack (this will cause the program to exit)
    assert(pop(myStack) == -1); // Uncomment this line to test stack underflow

    // Test pushing beyond capacity (stack overflow)
    push(myStack, 40);
    push(myStack, 50);
    push(myStack, 60);
    push(myStack, 70);
    push(myStack, 80);
    assert(size(myStack) == 5);
    push(myStack, 90); // This should print "Stack overflow" and not add the element
    assert(size(myStack) == 5);

    // Clean up
    memory_release(myStack);

    printf("All tests passed!\n");
}

int main() {
    // Test Stack data structure 

    test_stack();


    return 0;
}
