#pragma once
#include "magazin.h"
#include <vector>
#include "ValidatorAnimal.h"
#include "ValidatorProdus.h"
using namespace std;
class RepoFile {
protected:
	vector<Magazin*> magazin;
	string fileName;
	ValidatorAnimal validatorA;
	ValidatorMagazin validatorP;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();
	void setFileName(string fileName);
	vector<Magazin*> getAll();
	//vector<Animal*> getAllA();
	void insertR(int, Magazin*);
	int getSize();
	Magazin* getMagazin(int pos);
	void addMagazin(Magazin* m);
	void updateMagazin(Magazin* mVechi, Magazin* mNou);
	void deleteMagazin(Magazin* m);
	void emptyRepo();
	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};