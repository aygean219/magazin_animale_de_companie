#include "produse_magazin.h"
#include <vector>
#include <cstddef>
#include <string.h>
#include <sstream>
#include <ostream>
#include <iostream>
using namespace std;
Produs::Produs() :Magazin() {

}
Produs::Produs(double  cod, string nume, double  pret, string data_introducerii, double nr_exemplare_disponibile, string  data_expirarii) : Magazin(cod, nume, pret, data_introducerii, nr_exemplare_disponibile) {
	this->data_expirarii = data_expirarii;
}
Produs::Produs(const Produs& p) : Magazin(p) {
	this->data_expirarii = p.data_expirarii;
}
Magazin* Produs::clone()
{
	return new Produs(this->cod, this->nume, this->pret, this->data_introducerii, this->nr_exemplare_disponibile, this->data_expirarii);
}
Produs::~Produs() {

}
string Produs::getDataExpirarii()
{
	return this->data_expirarii;
}
void Produs::setDataExpirarii(string d)
{
	data_expirarii = d;
}
Produs& Produs::operator=(const Produs& p) {
	this->Magazin::operator=(p);
	this->setDataExpirarii(p.data_expirarii);
	return *this;
}
bool Produs::operator==(const Produs& p) {
	return this->Magazin::operator==(p) && (this->data_expirarii == p.data_expirarii);
}
string Produs::toStringDelimiter(string delim)
{
	return "Produs"+delim+Magazin::toStringDelimiter(delim) + delim + data_expirarii;
}