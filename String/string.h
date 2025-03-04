#ifndef STRING_H
#define STRING_H

/// @brief String data structure 
typedef struct {
    char* __str_ptr;
    int _length;
} String;

/// @brief Create a new String 
/// @param ch character sequence or "string" 
/// @return new String type 
String* create(char* ch);

/// @brief Prints the String 
/// @param str given string 
void print(String* str);

/// @brief Get the character at a specific index 
/// @param str given string 
/// @param INDEX index to get the character from 
/// @return character at the specified index 
char getCharAt(String* str, int INDEX);

/// @brief Update the character at a specific index 
/// @param str given string 
/// @param INDEX index to update the character at 
/// @param ch new character to set 
void updateCharAt(String* str, int INDEX, char ch);

/// @brief Delete the character at a specific index 
/// @param str given string 
/// @param INDEX index to delete the character from 
void deleteCharAt(String* str, int INDEX);

/// @brief Compare two strings 
/// @param str1 first string 
/// @param str2 second string 
/// @return 1 if equal, 0 if not equal
int compare(String* str1, String* str2);

/// @brief Find the first occurrence of a character in the string 
/// @param str given string 
/// @param ch character to find 
/// @return index of the character in the string, or -1 if not found 
int find(String* str, char ch);

/// @brief Reverse the string 
/// @param str given string 
void reverse(String* str);

/// @brief Concatenate a character sequence to the string 
/// @param str1 first string 
/// @param str2 character sequence to concatenate 
/// @return new String with concatenated content 
String* concatenate(String* str1, String* str2);

/// @brief Release the memory allocated for the string 
/// @param str string to release 
void memory_release(String* str);

#endif
