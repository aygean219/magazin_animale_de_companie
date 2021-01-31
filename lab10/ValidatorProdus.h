#pragma once
#include "ValidatorMagazin.h"
class ValidatorProdus :public ValidatorMagazin {
public:
	ValidatorProdus();
	~ValidatorProdus();
	void validate(Magazin* m);
};