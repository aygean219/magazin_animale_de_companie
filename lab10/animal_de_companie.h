#pragma once
#include <ostream>
#include <string>
#include "magazin.h"
using namespace std;
class Animal :public Magazin {
private:
	double  varsta;
public:
	Animal();
	Animal(double, string, double, string, double, double);
	Animal(const Animal&);
	Magazin* clone();
	~Animal();
	void setVarsta(double);
	double  getVarsta();
	Animal& operator=(const Animal&);
	bool operator==(const Animal&);
	string toStringDelimiter(string);
};