#pragma once
#include <stdbool.h>

#define is_a(ty)\
  ty parent

#define TYPE_MASK_SIZE sizeof(DataType) 

//------------------------Data Type------------------------//
typedef enum _DataType
{
	icloneable_t = 1 << 31,
	animal_t = (1 << 0) | icloneable_t,
	dog_t = (1 << 1) | animal_t,
} DataType;


bool is(void* target, DataType source);
void* tcalloc(size_t size);
void tfree(void* ptr);