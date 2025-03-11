# Arrays

## What is an Array?

- An array is a data structure used to store a collection of elements of the same type. Elements are stored at contiguous memory locations. Arrays have a fixed size; once declared, the size cannot be changed. Array indexing starts from 0 in most programming languages.

## Usage

- Storing collections: Arrays store multiple elements under a single variable.

## Examples:

- Array of integers.
- Array of strings (e.g., names of people).
- 2D or multidimensional arrays.

## Operations

- **Traversal**: Iterating through each element.
- **Insertion**: Adding an element at a specific index.
- **Deletion**: Removing an element by its index.
- **Updation**: Modifying an element's value.
- **Searching**: Finding an element by value.
- **Sorting**: Rearranging elements (ascending/descending order).

## Advantages

- **Fast access**: Constant time O(1) access via index.
- **Random access**: Any element can be directly accessed using its index.
- **Memory efficiency**: Elements are stored in adjacent memory blocks.

## Limitations

- **Fixed size**: Cannot resize after declaration.
- **Wasted memory**: Unused elements still occupy space.
- **Inflexibility**: Less suitable for dynamic data compared to linked lists or dynamic arrays.

## Algorithms

### Searching

- **Linear Search**: Iterate through each element until the key is found. Time complexity: O(n).
- **Binary Search**: Repeatedly divide the sorted array in half to find the key. Time complexity: O(log n).

### Sorting

- **Bubble Sort**: Repeatedly swap adjacent elements if they're in the wrong order. Time complexity: O(n²).
- **Selection Sort**: Select the smallest element and move it to its correct position. Time complexity: O(n²).
- **Insertion Sort**: Insert each element into its correct position in a sorted array. Time complexity: O(n²).
- **Quick Sort**: Partition the array around a pivot and recursively sort subarrays. Time complexity: O(n log n).
- **Merge Sort**: Divide the array in half, sort each half, and merge them. Time complexity: O(n log n).
- **Heap Sort**: Build a max-heap and repeatedly remove the largest element. Time complexity: O(n log n).
