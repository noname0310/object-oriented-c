#include <stdio.h>

#include "oop/typecast/type.h"
#include "oop/class/animal.h"
#include "oop/interface/cloneable.h"

//-----------------------------------------------------------//

int main()
{
	Animal* animal = (Animal*)new_Dog("포카칩");
	Dog* dog = (Dog*)animal;

	animal->override_print(animal); //"포카칩 is Dog"
	dog->parent.override_print(dog);//"포카칩 is Dog"

  printf("animal is animal? : %d\n", is(animal, animal_t));
  printf("dog is animal? : %d\n", is(dog, animal_t));

  printf("animal is clonable? : %d\n", is(animal, icloneable_t));
  printf("dog is clonable? : %d\n", is(dog, icloneable_t));

  ICloneable cloneable = animal->override_as_ICloneable(animal);
  Animal* clone = cloneable.Clone(cloneable.source);
  clone->override_print(animal);

	animal_delete(animal);
	return 0;
}