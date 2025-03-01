#ifndef ARRAY_H
#define ARRAY_H

/// @brief array data structure 
typedef struct Array {
    int* arr;
    unsigned int arr_pointer;
    unsigned int size;
} Array;

/// @brief create a new array 
/// @param N size of array 
/// @return a new array of N size 
Array* create(unsigned int N);

/// @brief adds element at the end in the array 
/// @param array array in which element has to add 
/// @param VAL the element to be added 
/// @return given array for reuse 
Array* push(Array* array, int VAL);

/// @brief removes last element from the given array 
/// @param array array from which element has to be removed 
/// @return given array 
Array* pop(Array* array);

/// @brief get first element of the given array 
/// @param array given array 
/// @return first element 
int get_first(Array* array);

/// @brief get last element of the given array 
/// @param array given array 
/// @return last element 
int get_last(Array* array);

/// @brief adds element at the specified INDEX in the array 
/// @param array array in which element has to add 
/// @param INDEX index on which element has to add 
/// @param VAL the element to be added 
/// @return given array for reuse 
Array* insert(Array* array, int INDEX, int VAL);

/// @brief delete element at any specific index 
/// @param array given array from which element has to delete 
/// @param INDEX INDEX at which element has to be removed 
/// @return given array 
Array* eliminate(Array* array, int INDEX);

/// @brief get element present at any INDEX in the given array 
/// @param array given array 
/// @param INDEX index 
/// @return element at INDEX in the given array 
int get(Array* array, int INDEX);

/// @brief update element with VAL at INDEX in the given array 
/// @param array given array 
/// @param INDEX INDEX of which element has to update 
/// @param VAL new value of element 
/// @return given array for reuse 
Array* update(Array* array, int INDEX, int VAL);

/// @brief returns size of the given array 
/// @param array given array 
/// @return size of array 
unsigned int size(Array* array);

/// @brief free up the memory occupied by the given array and set it to NULL 
/// @param array given array 
void memory_release(Array* array);

/// @brief reverse the given Array arr
/// @param arr given array 
void reverse(Array* arr);

/// @brief search element in Array 
/// @param arr given array 
/// @param key key to search in array 
/// @return index of key, -1 if key not found 
int search(Array* arr, int key);

/// @brief search element in sorted Array 
/// @param arr given sorted array 
/// @param key key to search in array 
/// @return index of key, -1 if key not found 
int search_binary(Array* arr, int key);

/// @brief sort the elements of given Array using bubble sort 
/// @param arr given array 
void bubble_sort(Array* arr);

/// @brief sort the elements of given Array using selection sort 
/// @param arr given array 
void selection_sort(Array* arr);

/// @brief sort the elements of given Array using insertion sort 
/// @param arr given array 
void insertion_sort(Array* arr);

/// @brief sort the elements of given Array using quick sort 
/// @param arr given array 
void quick_sort(Array* arr);

/// @brief sort the elements of given Array using merge sort 
/// @param arr given array 
void merge_sort(Array* arr);

/// @brief sort the elements of given Array using heap sort 
/// @param arr given array 
void heap_sort(Array* arr);

#endif
