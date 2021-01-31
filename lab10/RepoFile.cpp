#include "RepoFile.h"
#include "animal_de_companie.h"
#include "produse_magazin.h"
#include "magazin.h"
#include "ValidatorAnimal.h"
#include "ValidatorException.h"
#include "ValidatorMagazin.h"
#include "ValidatorProdus.h"
RepoFile::RepoFile()
{

}
RepoFile::RepoFile(string fileName)
{
	this->fileName = fileName;
}
RepoFile::~RepoFile()
{

}
void RepoFile::setFileName(string fileName)
{
	this->fileName = fileName;
}
vector<Magazin*> RepoFile::getAll()
{
	return this->magazin;
}
int RepoFile::getSize()
{
	return this->magazin.size();
}
Magazin* RepoFile::getMagazin(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->magazin[pos]->clone();
	}
	return new Magazin();
}
void RepoFile::insertR(int pos, Magazin* m)
{
	auto it = magazin.begin() + pos;
	auto newit = magazin.insert(it, m);
	this->saveToFile();
}
void RepoFile::addMagazin(Magazin* m) throw(ValidationException)
{
	if (typeid(*m) == (typeid(Animal)))
	{
		this->validatorA.validate(m);
	}
	if (typeid(*m) == (typeid(Produs)))
	{
		this->validatorP.validate(m);
	}
	this->magazin.push_back(m->clone());
	this->saveToFile();
}
void RepoFile::updateMagazin(Magazin* mVechi, Magazin* mNou)
{
	if (typeid(*mNou) == (typeid(Animal)))
	{
		this->validatorA.validate(mNou);
	}
	if (typeid(*mNou) == (typeid(Produs)))
	{
		this->validatorP.validate(mNou);
	}
	int k = this->magazin.size();
	for (int i = 0; i<k ; i++) {
		if (*(this->getMagazin(i)) == *mVechi)
		{
			delete this->magazin[i];
			this->magazin[i] = mNou->clone();
			this->saveToFile();
			return ;
		}
	}
}
void RepoFile::deleteMagazin(Magazin* m)
{
	int k = this->magazin.size();
	for (int i = 0; i <k ; i++)
	{
		if (**(this->magazin.begin() + i) == *m)
		{
			delete this->magazin[i];
			this->magazin.erase(this->magazin.begin() + i);
			this->saveToFile();
			return;
		}
	}
}
void RepoFile::emptyRepo()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->magazin[i];
	}
	this->magazin.clear();
}