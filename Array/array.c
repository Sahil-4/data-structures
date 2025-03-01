#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define THRESHOLD 10

void re_initialise(Array** array);

Array* create(unsigned int N) {
    Array* arrary = (Array*)malloc(sizeof(Array));

    arrary->arr = (int*)malloc(sizeof(int) * N);
    arrary->arr_pointer = 0;
    arrary->size = N;

    return arrary;
}

Array* push(Array* array, int VAL) {
    if (array->arr_pointer == array->size) re_initialise(&array);

    (array->arr)[array->arr_pointer] = VAL;
    array->arr_pointer++;

    return array;
}

Array* pop(Array* array) {
    if (array->arr_pointer <= 0) return array;
    array->arr_pointer--;
    return array;
}

int get_first(Array* array) {
    if (array->arr_pointer <= 0) return -1;
    return (array->arr)[0];
}

int get_last(Array* array) {
    if (array->arr_pointer <= 0) return -1;
    return (array->arr)[array->arr_pointer - 1];
}

Array* insert(Array* array, int INDEX, int VAL) {
    if (INDEX < 0 || INDEX >= array->arr_pointer) return array;

    int prev = VAL;
    for (int i = INDEX; i <= array->arr_pointer; i++) {
        int temp = array->arr[i];
        array->arr[i] = prev;
        prev = temp;
    }
    array->arr_pointer++;

    return array;
}

Array* eliminate(Array* array, int INDEX) {
    if (INDEX < 0 || INDEX >= array->arr_pointer) return array;

    for (int i = INDEX; i < array->arr_pointer; i++) {
        (array->arr)[i] = (array->arr)[i + 1];
    }
    array->arr_pointer--;

    return array;
}

int get(Array* array, int INDEX) {
    if (INDEX < 0 || INDEX >= array->arr_pointer) return -1;
    return (array->arr)[INDEX];
}

Array* update(Array* array, int INDEX, int VAL) {
    if (INDEX < 0 || INDEX >= array->arr_pointer) return array;
    (array->arr)[INDEX] = VAL;
    return array;
}

unsigned int size(Array* array) {
    return array->size;
}

void memory_release(Array* array) {
    free(array->arr);
    array->arr = NULL;
    array->arr_pointer = -1;
    array->size = 0;
    array = NULL;
}

/// @brief re initialise array with more capacity 
/// @param array : original array that has to be reinitialised 
void re_initialise(Array** array) {
    int t = (*array)->size;
    int t_plus = t + THRESHOLD;

    Array* temp = (Array*)malloc(sizeof(Array));
    temp = create(t_plus);

    for (int i = 0; i < (*array)->arr_pointer; i++) {
        push(temp, get(*array, i));
    }

    memory_release(*array);

    **array = *temp;
}

void __swap__(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void reverse(Array* arr) {
    int l = 0, h = arr->arr_pointer - 1;

    while (l < h) {
        __swap__(&(arr->arr)[l], &(arr->arr)[h]);
        l++, h--;
    }
}

int search_binary(Array* arr, int key) {
    int l = 0, h = arr->arr_pointer - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;
        int el = (arr->arr)[mid];

        if (el == key) return mid;
        else if (el < key) l = mid + 1;
        else h = mid - 1;
    }

    return -1;
}

int search(Array* arr, int key) {
    for (int i = 0; i < arr->arr_pointer; i++) {
        if ((arr->arr)[i] == key) return i;
    }

    return -1;
}

void bubble_sort(Array* arr) {
    int n = arr->arr_pointer;
    if (n < 2) return;

    for (int i = 1; i <= n; i++) {
        int check = 1;
        for (int j = 0; j < n - i; j++) {
            if ((arr->arr)[j] > (arr->arr)[j + 1]) {
                check = 0;
                __swap__(&(arr->arr)[j], &(arr->arr)[j + 1]);
            }
        }

        if (check) break;
    }
}

void selection_sort(Array* arr) {
    int n = arr->arr_pointer;
    if (n < 2) return;

    for (int i = 0; i < n; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if ((arr->arr)[j] < (arr->arr)[min_index]) min_index = j;
        }

        if (i == min_index) continue;
        __swap__(&(arr->arr)[i], &(arr->arr)[min_index]);
    }
}

void insertion_sort(Array* arr) {
    int n = arr->arr_pointer;
    if (n < 2) return;

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if ((arr->arr)[j] < (arr->arr)[j - 1]) {
                __swap__(&(arr->arr)[j], &(arr->arr)[j - 1]);
            }
        }
    }
}

void __merge__(Array* arr, int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    int* left = (int*)malloc(sizeof(int) * n1);
    int* right = (int*)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1 || i < n2; i++) {
        if (i < n1) left[i] = arr->arr[l + i];
        if (i < n2) right[i] = arr->arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr->arr[k] = left[i];
            i++;
        }
        else {
            arr->arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr->arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr->arr[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void __merge_sort__(Array* arr, int l, int h) {
    if (l >= h) return;

    int m = l + (h - l) / 2;

    __merge_sort__(arr, l, m);
    __merge_sort__(arr, m + 1, h);

    __merge__(arr, l, m, h);
}

void merge_sort(Array* arr) {
    if (arr->arr_pointer < 2) return;

    int l = 0, h = arr->arr_pointer - 1;
    __merge_sort__(arr, l, h);
}

int __partition__(Array* arr, int low, int high) {
    int pivot = arr->arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr->arr[j] <= pivot) {
            i++;
            __swap__(&(arr->arr[i]), &(arr->arr[j]));
        }
    }
    __swap__(&(arr->arr[i + 1]), &(arr->arr[high]));
    return (i + 1);
}

void __quick_sort__(Array* arr, int low, int high) {
    if (low < high) {
        int pi = __partition__(arr, low, high);
        __quick_sort__(arr, low, pi - 1);
        __quick_sort__(arr, pi + 1, high);
    }
}

void quick_sort(Array* arr) {
    if (arr->arr_pointer < 2) return;
    __quick_sort__(arr, 0, arr->arr_pointer - 1);
}

void __heapify__(Array* arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr->arr[left] > arr->arr[largest])
        largest = left;

    if (right < n && arr->arr[right] > arr->arr[largest])
        largest = right;

    if (largest != i) {
        __swap__(&(arr->arr[i]), &(arr->arr[largest]));
        __heapify__(arr, n, largest);
    }
}

void heap_sort(Array* arr) {
    int n = arr->arr_pointer;

    for (int i = n / 2 - 1; i >= 0; i--)
        __heapify__(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        __swap__(&(arr->arr[0]), &(arr->arr[i]));
        __heapify__(arr, i, 0);
    }
}
