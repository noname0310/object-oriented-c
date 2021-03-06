#pragma once
#include <stdbool.h>

#define is_a(ty)\
  ty parent

#define TYPE_MASK_SIZE sizeof(DataType) 

//------------------------Data Type------------------------//
typedef enum _DataType
{
	icloneable_t = 1 << 31,
	animal_t     = 1 << 0,
	dog_t        = 1 << 1,
} DataType;


bool is(void* target, DataType source);
void* tcalloc(size_t size, DataType type);
void tfree(void* ptr);

DataType getType(void* target);