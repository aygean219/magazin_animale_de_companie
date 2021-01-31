#include "magazin.h"
#include <cstddef>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "util.h"
using namespace std;
Magazin::Magazin() {
	this->cod = 0;
	this->pret = 0;
	this->nr_exemplare_disponibile = 0;
}
Magazin::Magazin(double cod, string nume, double pret, string data_introducerii, double  nr_exemplare_disponibile)
{
	this->nume = nume;
	this->data_introducerii = data_introducerii;
	this->cod = cod;
	this->pret = pret;
	this->nr_exemplare_disponibile = nr_exemplare_disponibile;

}
Magazin::Magazin(const Magazin& m)
{
	this->nume = m.nume;
	this->data_introducerii = m.data_introducerii;
	this->cod = m.cod;
	this->pret = m.pret;
	this->nr_exemplare_disponibile = m.nr_exemplare_disponibile;
}
Magazin* Magazin::clone()
{
	return new Magazin(this->cod, this->nume, this->pret, this->data_introducerii, this->nr_exemplare_disponibile);
}
Magazin::~Magazin() {
}
double Magazin::getCod()
{
	return this->cod;
}
string Magazin::getNume() {
	return this->nume;
}
double Magazin::getPret() {
	return this->pret;
}
string Magazin::getDataIntroducerii() {
	return this->data_introducerii;
}
double Magazin::getNrExemplareDisponibile() {
	return this->nr_exemplare_disponibile;
}
void Magazin::setCod(double cod) {
	this->cod = cod;
}
void Magazin::setNume(string t)
{
	nume = t;
}
void Magazin::setPret(double pret) {
	this->pret = pret;
}
void Magazin::setDataIntroducerii(string d)
{
	data_introducerii = d;
}
void Magazin::setNrExemplareDisponibile(double nr) {
	this->nr_exemplare_disponibile = nr;
}
Magazin& Magazin::operator=(const Magazin& m)
{
	this->setCod(m.cod);
	this->setNume(m.nume);
	this->setPret(m.pret);
	this->setDataIntroducerii(m.data_introducerii);
	this->setNrExemplareDisponibile(m.nr_exemplare_disponibile);
	return *this;
}
bool Magazin::operator==(const Magazin& m)
{
	return (this->cod == m.cod) && (this->pret == m.pret) && (this->nr_exemplare_disponibile == m.nr_exemplare_disponibile) && (nume == m.nume) && (data_introducerii == m.data_introducerii);
}
string Magazin::toStringDelimiter(string delim)
{
	return convertDoubleToString(cod) + delim + nume + delim + convertDoubleToString(pret) + delim + data_introducerii + delim + convertDoubleToString(nr_exemplare_disponibile);
}