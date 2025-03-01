#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"

void test() {
    // Create an array of size 5
    Array* arr = create(5);
    assert(arr != NULL);
    assert(arr->size == 5);
    assert(arr->arr_pointer == 0);
    printf("Array created successfully.\n");

    // Push elements into the array
    push(arr, 10);
    push(arr, 20);
    push(arr, 30);
    assert(arr->arr_pointer == 3);
    assert(arr->arr[0] == 10);
    assert(arr->arr[1] == 20);
    assert(arr->arr[2] == 30);
    printf("Elements pushed successfully.\n");

    // Get elements from the array
    assert(get(arr, 0) == 10);
    assert(get(arr, 1) == 20);
    assert(get(arr, 2) == 30);
    printf("Elements retrieved successfully.\n");

    // Insert an element at a specific index
    insert(arr, 1, 15);
    assert(arr->arr[0] == 10);
    assert(arr->arr[1] == 15);
    assert(arr->arr[2] == 20);
    assert(arr->arr[3] == 30);
    assert(arr->arr_pointer == 4);
    printf("Element inserted successfully.\n");

    // Update an element at a specific index
    update(arr, 1, 25);
    assert(arr->arr[1] == 25);
    printf("Element updated successfully.\n");

    // Eliminate an element at a specific index
    eliminate(arr, 1);
    assert(arr->arr[0] == 10);
    assert(arr->arr[1] == 20);
    assert(arr->arr[2] == 30);
    assert(arr->arr_pointer == 3);
    printf("Element eliminated successfully.\n");

    // Get the size of the array
    assert(size(arr) == 5);
    printf("Array size retrieved successfully.\n");

    // Get the first and last elements of the array
    assert(get_first(arr) == 10);
    assert(get_last(arr) == 30);
    printf("First and last elements retrieved successfully.\n");

    // Pop an element from the array
    pop(arr);
    assert(arr->arr_pointer == 2);
    assert(arr->arr[0] == 10);
    assert(arr->arr[1] == 20);
    printf("Element popped successfully.\n");

    // Adding more element to test sorting 
    push(arr, 5);
    push(arr, 4);
    push(arr, 1);
    assert(arr->arr_pointer == 5);
    assert(arr->arr[0] == 10);
    assert(arr->arr[1] == 20);
    assert(arr->arr[2] == 5);
    assert(arr->arr[3] == 4);
    assert(arr->arr[4] == 1);

    // Sort elements of the array 
    // bubble_sort(arr);
    // selection_sort(arr);
    // insertion_sort(arr);
    // merge_sort(arr);
    // quick_sort(arr);
    heap_sort(arr);
    assert(arr->arr_pointer == 5);
    assert(arr->arr[0] == 1);
    assert(arr->arr[1] == 4);
    assert(arr->arr[2] == 5);
    assert(arr->arr[3] == 10);
    assert(arr->arr[4] == 20);
    printf("Array sorted successfully.\n");

    assert(search(arr, 1) == 0);
    assert(search(arr, 5) == 2);
    assert(search(arr, 7) == -1);
    printf("Array linear search successfully.\n");

    assert(search_binary(arr, 1) == 0);
    assert(search_binary(arr, 5) == 2);
    assert(search_binary(arr, 7) == -1);
    printf("Array binary search successfully.\n");

    // Free the memory allocated to the array
    memory_release(arr);
    printf("Memory released successfully.\n");

    printf("All operations tested successfully.\n");
}

int main() {
    // TEST : Implemented dynamic array 
    // FOR : [ create, push, pop, insert, get, update, delete, size, get_first, get_last, memory_release ]
    // : [ sorting_algos, searching_algos ]
    // NOTE : array should be a dynamic data structure that can increase the size if needed  

    test();


    return 0;
}
