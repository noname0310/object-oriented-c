#include <stdlib.h>
#include "type.h"

bool is(void* target, DataType source)
{
  DataType type = *(DataType*)target;
  return type & source;
}

void* tcalloc(size_t size, DataType type_mask) 
{
  char* ptr = (char*)calloc(1, TYPE_MASK_SIZE + size);
  
  return (void*)(ptr + TYPE_MASK_SIZE);
}

void tfree(void* ptr)
{
  size_t addr = (size_t)ptr;
  addr -= TYPE_MASK_SIZE;
  free((void*)addr);
}