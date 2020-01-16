#include <stdlib.h>
#include "type.h"

bool is(void* target, DataType source)
{
  DataType type = getType(target);
  return type & source;
}

void* tcalloc(size_t size, DataType type)
{
  void* ptr = calloc(1, (TYPE_MASK_SIZE + size));
  *(DataType*)ptr = type;
  return (void*)(ptr + TYPE_MASK_SIZE);
}

void tfree(void* ptr)
{
  free((void*)(ptr - TYPE_MASK_SIZE));
}

DataType getType(void* target)
{
  return *(DataType*)(target - TYPE_MASK_SIZE);
}