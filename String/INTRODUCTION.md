# Strings

## What is a String?

- A **string** is a sequence of characters used to represent text.
- Characters are stored in contiguous memory locations.
- In some programming languages (like C), strings are typically terminated with a null character (`'\0'`) to mark the end.
- Characters can be accessed using their index, similar to array elements.

## Usage

- **Text Processing**: Manipulating and analyzing text data.
- **Pattern Matching**: Used in regular expressions (regex) for searching and matching patterns.
- **Data Compression**: Techniques like Huffman coding and run-length encoding use strings to compress data.

## Operations

- **Insert Character**: Adding a character at a specific index.
- **Delete Character**: Removing a character from a specific index.
- **Search**: Finding a substring or character within the string.
- **Compare**: Comparing two strings for equality or ordering.
- **Concatenate**: Joining two strings to form a new string.

## Advantages

- **Fundamental Data Type**: Essential in most programming languages.
- **Ease of Use**: Conveniently represents real-world entities like names, locations, etc.

## Limitations

- **Immutability**: In many languages, strings are immutable, meaning they cannot be changed once created. Operations that modify strings usually create new strings.
- **Concatenation Performance**: Repeated concatenation can be slow due to the creation of new strings each time.
- **Encoding Compatibility**: Issues may arise with different encoding standards (e.g., UTF-8, UTF-16), potentially affecting compatibility.

## Algorithms

### Insert Character at Index

1. Allocate space for a new string (size = old size + 1).
2. Copy characters from the original string to the new string, stopping at the insertion index.
3. Insert the new character at the given index.
4. Copy the remaining characters from the original string.
5. Add null character at the end.

### Delete Character at Index

1. Check if the index is valid.
2. Shift all characters to the left from the deletion point.
3. Decrease the string length by 1.
4. Add null character at the end.

### Search for a Character

1. Iterate through each character of the string.
2. If a match is found, return the index.
3. If no match is found, return -1.

### Compare Two Strings

1. Compare lengths; if unequal, return false.
2. Iterate through each character of both strings.
3. If any pair of characters don’t match, return false.
4. If all characters match, return true.

### Concatenate Two Strings

1. Allocate space for a new string (size = length of string1 + length of string2).
2. Copy all characters from string1 to the new string.
3. Append all characters from string2 to the new string.
4. Add null character at the end.

### Reverse a String

1. Initialize two pointers, one at the start and one at the end of the string.
2. Swap the characters at both pointers.
3. Move the start pointer forward and the end pointer backward.
4. Repeat until pointers meet.
