#pragma once
#include <ostream>
#include <string>
#include "magazin.h"
using namespace std;
class Produs :public Magazin {
private:
	string data_expirarii;
public:
	Produs();
	Produs(double, string, double, string, double, string);
	Produs(const Produs&);
	Magazin* clone();
	~Produs();
	void setDataExpirarii(string);
	string getDataExpirarii();
	Produs& operator=(const Produs&);
	bool operator==(const Produs&);
	string toStringDelimiter(string);
};