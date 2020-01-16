#pragma once

//-------------------------ICloneable------------------------//
typedef struct _ICloneable
{
  void* source;
  void* (*as_source)(struct _ICloneable* self);
	void* (*Clone)(void*);
} ICloneable;

ICloneable _ICloneable(void* source, void* (*Clone)(void*));
void* ICloneable_As_Source(ICloneable* self);