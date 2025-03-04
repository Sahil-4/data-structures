#include <stdio.h>
#include <assert.h>
#include "string.h"

void test() {
    // Create a new String
    String* str = create("hi there");
    assert(str != NULL);
    assert(str->_length == 8);

    String* temp = create("hi there");
    assert(compare(str, temp) == 1);
    memory_release(temp);

    // Print the String
    print(str); // Expected output: hi there

    // Get character at index
    assert(getCharAt(str, 0) == 'h');
    assert(getCharAt(str, 3) == 't');
    assert(getCharAt(str, 8) == '\0'); // Out of bounds

    // Update character at index
    updateCharAt(str, 3, 'T');
    assert(getCharAt(str, 3) == 'T');
    updateCharAt(str, 10, 'x'); // Out of bounds, should do nothing

    // Delete character at index
    deleteCharAt(str, 3);
    assert(str->_length == 7);

    temp = create("hi here");
    assert(compare(str, temp) == 1);
    memory_release(temp);

    // Find character in string
    assert(find(str, 'h') == 0);
    assert(find(str, 'e') == 4);
    assert(find(str, 'x') == -1);

    // Reverse the string
    reverse(str);

    temp = create("ereh ih");
    assert(compare(str, temp) == 1);
    memory_release(temp);

    // Concatenate strings
    String* str2 = create(" there");
    String* concatenatedStr = concatenate(str, str2);

    temp = create("ereh ih there");
    assert(compare(concatenatedStr, temp) == 1);
    memory_release(temp);

    // Memory release
    memory_release(str);
    memory_release(str2);
    memory_release(concatenatedStr);

    printf("All tests passed!\n");
}

int main() {
    // Test String data structure implementation
    test();

    return 0;
}
