#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include "math.h"
#include "memory.h"

/**
 *
 * @param str
 * @return the lenght of the string
 */
int string_length(const char *str);

/** create a copy of a string to the heap
 *
 * @param str
 * @return copy of the string
 */
char *string_copy(const char *str);

/** split a string based on a specific delimiter
 *
 * @param str the string to split
 * @param delim the delimiter
 * @return array containing the split elements from the string
 */
char **string_split(const char *str, char delim);

/** concatenate two string
 *
 * @param str1
 * @param str2
 * @return str1 + str2
 */
char *string_concat(const char *str1, const char *str2);

/** remove the last characters of a string
 *
 * @param str
 * @param n the number of characters to remove (n >= 0)
 */
void strip(char *str, const int n);

/** print the string until encountering a newline
*
 * @param str
 * @param b the first character to print
 */
void print_string(const char *str, int b);

/** test if a string's beginning is equal to another one
 *
 * @param str1 the string to test
 * @param str2 the beginning string
 * @return true if and only if str1 begins by str2
 */
bool string_begin(const char *str1, const char *str2);

/** test if two strings are equal
 *
 * @param str1
 * @param str2
 * @return true if and only if str1 = str2
 */
bool string_equal(const char *str1, const char *str2);

/** free the memory associated to a string array
 *
 * @param array
 */
void free_string_array(char **array);

#endif //STRING_H