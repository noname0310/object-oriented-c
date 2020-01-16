#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../typecast/type.h"
#include "animal.h"
#include "../interface/cloneable.h"

//-----------------------Animal Methods-----------------------//
Animal* new_Animal(char* name)
{
	size_t strlength = strlen(name) + 1;
	char* Name = (char*)calloc(1, strlength);
	if (Name != NULL)
		strcpy(Name, name);

	Animal instance =
	{
		.type = animal_t,
		.name = Name,
		.delete = Animal_Delete,
		.override_print = Animal_Override_Print,
    .override_as_ICloneable = Animal_As_ICloneable,
    .override_Clone = Animal_Override_Clone
	};

	Animal* pinstance = (Animal*)tcalloc(sizeof(Animal), animal_t);
  if (pinstance != NULL)
		*pinstance = instance;

  return pinstance;
}

Animal _Animal(char* name)
{
	size_t strlength = strlen(name) + 1;
	char* Name = (char*)calloc(1, strlength);
	if (Name != NULL)
		strcpy(Name, name);

	Animal instance =
	{
		.type = animal_t,
		.name = Name,
		.delete = Animal_Delete,
		.override_print = Animal_Override_Print,
    .override_as_ICloneable = Animal_As_ICloneable,
    .override_Clone = Animal_Override_Clone
	};

	return instance;
}

void Animal_Delete(Animal* self)
{
#ifdef DEBUG
  printf("[info] delete %s\n", self->name);
#endif
	free(self->name);
	if (self->type == animal_t)
		tfree(self);
}

void Animal_Override_Print(void* self)
{
	printf("%s is Animal\n", ((Animal*)self)->name);
}

ICloneable Animal_As_ICloneable(void *self)
{
  return _ICloneable(self, Animal_Override_Clone);
}

void* Animal_Override_Clone(void* self)
{
  Animal* cloned = new_Animal(((Animal*)self)->name);  
  return cloned;
}

//---------------------------------------------------------//

//-----------------------Dog Methods------------------------//
Dog* new_Dog(char* name)
{
	Animal parentinstance = _Animal(name);
	parentinstance.type = dog_t;
	parentinstance.override_print = Dog_Override_Print;
  parentinstance.override_as_ICloneable = Dog_As_ICloneable;
  parentinstance.override_Clone = Dog_Override_Clone;

	Dog instance =
	{
		.parent = parentinstance,
		.delete = Dog_Delete
	};

	Dog* pinstance = (Dog*)tcalloc(sizeof(Animal), dog_t);
	if (pinstance != NULL)
		*pinstance = instance;

	return pinstance;
}

void Dog_Delete(Dog* self)
{
  printf("delete dog: %s\n", self->parent.name);
	self->parent.delete(&self->parent);
	tfree(self);
}

void Dog_Override_Print(void* self)
{
	printf("%s is Dog\n", ((Dog*)self)->parent.name);
}

ICloneable Dog_As_ICloneable(void *self)
{
  return _ICloneable(self, Dog_Override_Clone);
}

void* Dog_Override_Clone(void* self)
{
  Dog* cloned = new_Dog(((Dog*)self)->parent.name);  
  return cloned;
}
//------------------------------------------------------------//

//-----------------------Delete Method-----------------------//
void animal_delete(void* obj)
{
	switch (((Animal*)obj)->type)
	{
	case animal_t:
		((Animal*)obj)->delete(obj);
		break;
	case dog_t:
		((Dog*)obj)->delete(obj);
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------//
