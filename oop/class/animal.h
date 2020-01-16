#pragma once

#include "../typecast/type.h"
#include "../interface/cloneable.h"

//-----------------------Animal Class----------------------//
//-----------------------Animal Struct---------------------//
typedef struct _Animal
{
	DataType type;
	char* name;
	void (*delete)(struct _Animal*);
	void (*override_print)(void*);
  ICloneable (*override_as_ICloneable)(void*);
	void* (*override_Clone)(void*);
} Animal;
//---------------------------------------------------------//

//------------------Animal Method Declar-------------------//
Animal* new_Animal(char* name);
Animal _Animal(char* name);
void Animal_Delete(Animal* self);

void Animal_Override_Print(void* self);

//ICloneable Impl
ICloneable Animal_As_ICloneable(void *self);
void* Animal_Override_Clone(void* self);

//---------------------------------------------------------//

//-------------------------Dog Class-----------------------//
//-------------------------Dog Struct----------------------//
typedef struct _Dog
{
  is_a(Animal);
	void (*delete)(struct _Dog*);
} Dog;
//---------------------------------------------------------//

//-------------------Dog Method Declar---------------------//
Dog* new_Dog(char* name);
void Dog_Delete(Dog* self);

void Dog_Override_Print(void* self);

//ICloneable Impl
ICloneable Dog_As_ICloneable(void *self);
void* Dog_Override_Clone(void* self);
//---------------------------------------------------------//

//------------------------Utils----------------------------//
void animal_delete(void* obj);
//---------------------------------------------------------//