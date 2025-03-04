#include <stdio.h>
#include <stdlib.h>
#include "string.h"

String* create(char* ch) {
    if (!ch) return NULL; // Check for null input

    String* str = (String*)malloc(sizeof(String));
    if (!str) return NULL; // Check memory allocation

    str->_length = 0;
    while (ch[str->_length] != '\0') {
        str->_length++;
    }
    str->__str_ptr = (char*)malloc(sizeof(char) * (str->_length + 1));
    if (!str->__str_ptr) {
        free(str);
        return NULL;
    }

    for (int i = 0; i < str->_length; i++) {
        str->__str_ptr[i] = ch[i];
    }
    str->__str_ptr[str->_length] = '\0';

    return str;
}

void print(String* str) {
    if (!str || !str->__str_ptr) return;
    printf("%s\n", str->__str_ptr);
}

char getCharAt(String* str, int INDEX) {
    if (!str || INDEX < 0 || INDEX >= str->_length) return '\0';
    return str->__str_ptr[INDEX];
}

void updateCharAt(String* str, int INDEX, char ch) {
    if (!str || INDEX < 0 || INDEX >= str->_length) return;
    str->__str_ptr[INDEX] = ch;
}

void deleteCharAt(String* str, int INDEX) {
    if (!str || INDEX < 0 || INDEX >= str->_length) return;

    for (int i = INDEX; i < str->_length - 1; i++) {
        str->__str_ptr[i] = str->__str_ptr[i + 1];
    }
    str->__str_ptr[--(str->_length)] = '\0';
}

int compare(String* str1, String* str2) {
    if (!str1 || !str2) return 0;
    if (str1->_length != str2->_length) return 0;

    for (int i = 0; i < str1->_length; i++) {
        if (str1->__str_ptr[i] != str2->__str_ptr[i]) return 0;
    }
    return 1; // 1 means equal
}

int find(String* str, char ch) {
    if (!str) return -1;
    for (int i = 0; i < str->_length; i++) {
        if (str->__str_ptr[i] == ch) return i;
    }
    return -1;
}

void reverse(String* str) {
    if (!str) return;

    int left = 0;
    int right = str->_length - 1;
    while (left < right) {
        char temp = str->__str_ptr[left];
        str->__str_ptr[left] = str->__str_ptr[right];
        str->__str_ptr[right] = temp;
        left++;
        right--;
    }
}

String* concatenate(String* str1, String* str2) {
    if (!str1 || !str2) return NULL;

    int len = str1->_length + str2->_length;

    String* str = (String*)malloc(sizeof(String));
    if (!str) return NULL;

    str->__str_ptr = (char*)malloc(sizeof(char) * (len + 1));
    if (!str->__str_ptr) {
        free(str);
        return NULL;
    }

    for (int i = 0; i < str1->_length; i++) {
        str->__str_ptr[i] = str1->__str_ptr[i];
    }
    for (int i = 0; i < str2->_length; i++) {
        str->__str_ptr[i + str1->_length] = str2->__str_ptr[i];
    }
    str->__str_ptr[len] = '\0';
    str->_length = len;

    return str;
}

void memory_release(String* str) {
    if (!str) return;
    free(str->__str_ptr);
    free(str);
}
