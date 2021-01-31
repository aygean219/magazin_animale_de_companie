#include "ValidatorMagazin.h"
#include "ValidatorException.h"
#include <string.h>
#include "util.h"
#include <iostream>
using namespace std;
ValidatorMagazin::ValidatorMagazin()
{

}
ValidatorMagazin::~ValidatorMagazin()
{

}
void ValidatorMagazin::validate(Magazin* m)
{
	if (m->getCod() < 0)
	{
		throw ValidationException("Codul trebuie sa fie pozitiv!!");
	}
	if (m->getNume().empty())
	{
		throw ValidationException("Numele trebuie sa existe");
	}
	if (m->getNrExemplareDisponibile() < 0)
	{
		throw ValidationException("Numarul de exemplare trebuie sa fie pozitiv!!");
	}
	if (m->getPret() < 0)
	{
		throw ValidationException("Pretul trebuie sa fie pozitiv!!");
	}
	if (verifiDate(m->getDataIntroducerii())!=true)
	{
		throw ValidationException("Data trebuie sa fie una valida!!");
	}
}