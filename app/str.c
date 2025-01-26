#include "str.h"

int string_length(const char *str)
{
  int i = 0;
  while (str[i] != '\0')
  {
    i++;
  }
  return i;
}

char *string_copy(const char *str)
{
  const int l = string_length(str);
  char *result = memory_alloc((l + 1) * sizeof(char));
  for (int i = 0; i <= l; i++)
  {
    result[i] = str[i];
  }
  return result;
}

char **string_split(const char *str, const char delim)
{
  // Create the result list
  int size = 1;
  int i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == delim)
      size++;
    i++;
  }
  char **result = memory_alloc((size + 1) * sizeof(char *));

  // Complete the list
  int p = 0; // the actual world
  int begin = 0;
  int wSize = 0; // word size
  i = 0;
  while (str[i] != '\0')
  {
    if (str[i + 1] == delim || str[i + 1] == '\0')
    {
      wSize = i - begin + 1;
      result[p] = memory_alloc((wSize + 1) * sizeof(char));
      for (int j = 0; j < wSize; j++)
        result[p][j] = str[begin + j];
      result[p][wSize] = '\0';
      begin = begin + wSize + 1;
      p++;
    }
    i++;
  }

  result[size] = NULL;
  return result;
}

char *string_concat(const char *str1, const char *str2)
{
  const int size1 = string_length(str1);
  const int size2 = string_length(str2);
  const int size = size1 + size2;
  char *result = memory_alloc((size + 1) * sizeof(char));

  for (int i = 0; i < size1; i++)
    result[i] = str1[i];
  for (int i = 0; i < size2; i++)
    result[size1 + i] = str2[i];
  result[size] = '\0';
  return result;
}

void strip(char *str, const int n)
{
  int l = 0;
  while (str[l] != '\0')
  {
    l++;
  }

  str[max(0, l - n)] = '\0';
}

void print_string(const char *str, const int b)
{
  int i = b;
  while (str[i] != '\0' && str[i] != '\n')
  {
    printf("%c", str[i]);
    i++;
  }
}

bool string_begin(const char *str1, const char *str2)
{
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0')
  {
    if (str1[i] != str2[i])
      return false;
    i++;
  }
  return str2[i] == '\0';
}

bool string_equal(const char *str1, const char *str2)
{
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0')
  {
    if (str1[i] != str2[i])
      return false;
    i++;
  }
  return str1[i] == str2[i];
}

void free_string_array(char **array)
{
  int i = 0;
  while (array[i] != NULL)
  {
    free(array[i]);
    i++;
  }
  free(array);
}