#include "ValidatorAnimal.h"
#include "animal_de_companie.h"
#include "ValidatorException.h"

ValidatorAnimal::ValidatorAnimal()
{

}
ValidatorAnimal::~ValidatorAnimal()
{

}
void ValidatorAnimal::validate(Magazin* m)
{
	ValidatorMagazin::validate(m);
	Animal* a = (Animal*)m;
	if (a->getVarsta() < 0)
	{
		throw ValidationException("Varsta trebuie sa fie pozitiva!");
	}
}