#include "cloneable.h"

ICloneable _ICloneable(void* source, void* (*Clone)(void*))
{
  ICloneable instance =
  {
    .source = source,
    .as_source = ICloneable_As_Source,
    .Clone = Clone
  };
  return instance;
}

void* ICloneable_As_Source(ICloneable* self)
{
  return self->source;
}