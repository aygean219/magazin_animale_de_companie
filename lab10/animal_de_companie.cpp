#include "animal_de_companie.h"
#include "util.h"
#include <cstddef>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
#include <iostream>
using namespace std;
Animal::Animal() :Magazin() {
	this->varsta = 0;
}
Animal::Animal(double  cod, string nume, double pret, string data_introducerii, double  nr_exemplare_disponibile, double varsta) : Magazin(cod, nume, pret, data_introducerii, nr_exemplare_disponibile) {
	this->varsta = varsta;
}
Animal::Animal(const Animal& a) : Magazin(a) {
	this->varsta = a.varsta;
}
Magazin* Animal::clone()
{
	return new Animal(this->cod, this->nume, this->pret, this->data_introducerii, this->nr_exemplare_disponibile, this->varsta);
}
Animal::~Animal() {

}
void Animal::setVarsta(double  v)
{
	this->varsta = v;
}
double  Animal::getVarsta()
{
	return this->varsta;
}
bool Animal::operator==(const Animal& a)
{
	return this->Magazin::operator==(a) && (this->varsta == a.varsta);
}
Animal& Animal::operator=(const Animal& a) {
	this->Magazin::operator=(a);
	this->setVarsta(a.varsta);
	return *this;
}
string Animal::toStringDelimiter(string delim)
{
	return "Animal" + delim + Magazin::toStringDelimiter(delim) + delim + convertDoubleToString(varsta);
}