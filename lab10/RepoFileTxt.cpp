#include "RepoFileTxt.h"
#include <fstream>
#include "animal_de_companie.h"
#include "produse_magazin.h"
#include "ReadFromFileException.h"
RepoFileTxt::RepoFileTxt() :RepoFile()
{
}
RepoFileTxt::RepoFileTxt(string fileName) : RepoFile(fileName)
{
}
RepoFileTxt::~RepoFileTxt()
{
}
void RepoFileTxt::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = " ";
	
			while (getline(f, linie))
			{
				if (linie.substr(0, 6) == "Animal")
				{
					linie = linie.erase(0, 7);

					int pos = linie.find(delim);
					double cod = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double pret = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string data_introducerii = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double nr_de_exemplare = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double varsta = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);



					Animal* an = new Animal(cod, nume, pret, data_introducerii, nr_de_exemplare, varsta);
					this->magazin.push_back(an);
				}
				else if (linie.substr(0, 6) == "Produs")
				{
					linie = linie.erase(0, 7);

					int pos = linie.find(delim);
					double cod = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string nume = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double pret = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string data_introducerii = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					double nr_de_exemplare = stod(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string data_expirarii = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					Produs* pr = new Produs(cod, nume, pret, data_introducerii, nr_de_exemplare, data_expirarii);
					this->magazin.push_back(pr);
				}
			}
		
		f.close();
	}

}
void RepoFileTxt::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Magazin* elem : this->magazin)
		{
			f << elem->toStringDelimiter(" ") << endl;
		}
	}
}