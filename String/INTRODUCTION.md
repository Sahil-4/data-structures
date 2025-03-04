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
