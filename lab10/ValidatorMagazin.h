#pragma once
#include <string>
#include "magazin.h"
using namespace std;
class ValidatorMagazin {
public:
	ValidatorMagazin();
	~ValidatorMagazin();
	virtual void validate(Magazin* m);
};