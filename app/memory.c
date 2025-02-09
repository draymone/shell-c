//
// Created by OGM on 26/12/2024.
//

#include "memory.h"

void *memory_alloc(size_t size)
{
  void *ptr = malloc(size);
  if (ptr == NULL)
  {
    fprintf(stderr, "memory_alloc failed\n");
    exit(1);
  }
  return ptr;
}
