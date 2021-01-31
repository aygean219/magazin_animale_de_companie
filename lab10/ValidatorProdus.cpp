#include "ValidatorProdus.h"
#include "produse_magazin.h"
#include "ValidatorException.h"
#include "util.h"
#include <iostream>
ValidatorProdus::ValidatorProdus()
{

}
ValidatorProdus::~ValidatorProdus()
{
}
void ValidatorProdus::validate(Magazin* m)
{
	ValidatorMagazin::validate(m);
	Produs* p = (Produs*)m;
	if (verifiDate(p->getDataExpirarii()) != true)
	{
		throw ValidationException("Data expirarii nu este valida");
	}

}