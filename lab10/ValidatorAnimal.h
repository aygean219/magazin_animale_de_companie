#pragma once
#include "ValidatorMagazin.h"
class ValidatorAnimal :public ValidatorMagazin {
public:
	ValidatorAnimal();
	~ValidatorAnimal();
	void validate(Magazin*);
};