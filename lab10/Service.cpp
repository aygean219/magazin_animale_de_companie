#include "my_exception.h"
#include "my_exception2.h"
#include "exceptii2.h"
#include "exceptii3.h"
#include <stdlib.h>
#include "Service.h"
#include "user.h"
#include <vector>
#include <typeinfo>
#include <iostream>
#include "ValidatorException.h"
#include "ReadFromFileException.h"
#include "util.h"
using namespace std;
Service::Service()
{

}
Service::Service(RepoFile* repoMagazin, RepoUser* repoUsers)
{
	this->repoMagazin = repoMagazin;
	this->repoUsers = repoUsers;
	User* u1=new User("aa", "bb");
	User* u2=new User("cc", "dd");
	repoUsers->addUser(u1);
	repoUsers->addUser(u2);
}
void Service::setRepoUser(RepoUser* repoUser)
{
	this->repoUsers = repoUser;
	/*User* u1 = new User("aa", "bb");
	User* u2 = new User("cc", "dd");
	repoUsers->addUser(u1);
	repoUsers->addUser(u2);*/
}
void Service::setRepoFile(RepoFile* repoFile)
{
	this->repoMagazin = repoFile;
}
void Service::repoInit(string fileName)
{
	repoMagazin->setFileName(fileName);
	repoMagazin->loadFromFile();
}
void Service::cumparare(int cod, int numar) 
{
	vector<Magazin*> aa = repoMagazin->getAll();
	int okc = 0;
	int okn = 0;
	if (cod < 0)
	{
		throw ValidationException("Codul trebuie sa fie pozitiv!!");
	}
	for (Magazin* current : aa)
	{
		if (current->getCod() == cod)
		{
			okc = 1;
			if (current->getNrExemplareDisponibile() >= numar)
			{
				okn = 1;
				int m = current->getNrExemplareDisponibile()- numar;
				current->setNrExemplareDisponibile(m);
			}
		}
	}
	if (okc == 0)
	{
		throw MyException("Nu s-a gasit codul!!");
	}
	if (okn == 0 && okc == 1)
	{
		throw MyException22("Numarul de exemplare introdus este prea mare");
	}
}
vector<Magazin*> Service::find_by_name(string name)
{
	vector<Magazin*> aa = repoMagazin->getAll();
	vector<Magazin*> rez;
	int ok = 0;
	if (name==" ")
	{
		throw ValidationException("Numele trebuie sa existe");
	}
	for (Magazin* current : aa)
	{
		if (current->getNume() == name)
		{
			ok = 1;
			rez.push_back(current);
		}
	}
	if (ok == 0)
	{
		throw MyException("Numele nu exista!!");
	}
	return rez;
}
vector<Magazin*> Service::find_by_date(string date)
{
	vector<Magazin*> aa = repoMagazin->getAll();
	vector<Magazin*> rez;
	int ok = 0;
	if (verifiDate(date) != true)
	{
		throw ValidationException("Data trebuie sa fie una valida!!");
	}
	for (Magazin* current : aa)
	{
		if (current->getDataIntroducerii() == date)
		{
			ok = 1;
			rez.push_back(current);
		}
	}
	if (ok == 0)
	{
		throw MyException("Data nu exista!!");
	}
	return rez;
}
void Service::usersInit(RepoUser* repoUser)
{
	User* u1 = new User("aa", "bb");
	User* u2 = new User("cc", "dd");
	repoUsers->addUser(u1);
	repoUsers->addUser(u2);

}
bool Service::login(string u, string p)
{
	User* usr = new User(u, p);
	int m = repoUsers->find(usr);
	return (m != -1);
}
void Service::logout(string n, string p)
{
	User* usr = new User(n, p);
	repoUsers->deleteUser(usr);
}
void Service::insertt(int pos, Magazin* m)
{
	int ok1 = 0, ok2 = 0;
	if (pos<0 || pos>repoMagazin->getSize())
	{
		ok1 = 1;
		//throw MyException("Pozitia nu exista!!!");
	}
	vector<Magazin*> s = repoMagazin->getAll();
	for (Magazin* current : s)
	{
		if (current->getCod() == m->getCod())
		{
			ok2 = 1;
			//throw MyException22("Codul exista deja pe alta pozitie si nu se poate realiza upd!!!!");
		}
	}
	int ok3 = 1;
	if (ok1 == 1 && ok2 == 0)
	{
		ok3 = 0;
		throw MyException("Pozitia nu exista!!!");
	}
	if (ok1 == 0 && ok2 == 1)
	{
		ok3 = 0;
		throw MyException22("Codul exista deja pe alta pozitie si nu se poate realiza upd!!!!");

	}
	if (ok3== 0)
	{
		throw MyException3("Codul exista sau pozitia nu exista!!");
	}
	for (int i=0;i<repoMagazin->getSize();i++)
	{	
		if (i == pos)
		{
			repoMagazin->insertR(pos, m);
		}
	}
}
void Service::add(Magazin* m) throw(ValidationException)
{
	vector<Magazin*> s = repoMagazin->getAll();
	for (Magazin* current : s)
	{
		if (current->getCod() == m->getCod())
		{
		
			throw MyException("Codul exista deja!!!!");
		}
	}
	repoMagazin->addMagazin(m);
}
void Service::add2(Magazin* m)
{	
	int ok1 = 0, ok2 = 0;
	vector<Magazin*> s = repoMagazin->getAll();
	/*for (Magazin* ct : s)
	{

	}*/
	for (Magazin* current : s)
	{
		if (ok1 == ok2) {
			//int ok1 = 0, ok2 = 0;
			if (current->getCod() == m->getCod() && current->getNume() == m->getNume())
			{
				int n = current->getNrExemplareDisponibile() + m->getNrExemplareDisponibile();
				current->setNrExemplareDisponibile(n);
				ok1 = 1;
			}
			else
			{
				if (current->getCod() == m->getCod() && current->getNume() != m->getNume())
				{
					repoMagazin->addMagazin(m);
					ok2 = 1;
				}
				
			}

		}
		

		}
	
	if (ok1 == 0 && ok2 == 0)
	{
		repoMagazin->addMagazin(m);
	}
	
}
int Service::deletee(int codul,Magazin* m)
{	
	vector<Magazin*> k = repoMagazin->getAll();
	for (Magazin* current : k)
	{ 
		if ((current->getCod() == codul) && (typeid(*current).name() != typeid(*m).name()))
			throw MyException2("Ati introdus codul unui obiect de tip: ",typeid(*current).name());
		else
		{
			if ((current->getCod() == codul) && (typeid(*current).name() == typeid(*m).name()))
			{
				Magazin* m = new Magazin(codul, current->getNume(), current->getPret(), current->getDataIntroducerii(), current->getNrExemplareDisponibile());
				repoMagazin->deleteMagazin(m);
				return 0;
			}
		}

	}
	throw MyException("Codul introdus nu se afla in baza de date!!!");
	
}
int Service::get_size()
{
	return this->repoMagazin->getSize();
}
int Service::update(int codul, Magazin* mN,Magazin* a)throw(ValidationException)
{	
	vector<Magazin*> s = repoMagazin->getAll();
	for (Magazin* current : s)
	{
		if ((current->getCod() == codul) && (typeid(*current).name() != typeid(*a).name()))
			throw MyException2("Ati introdus codul unui obiect de tip: ", typeid(*current).name());
		else
		{
			if ((current->getCod() == codul) && (typeid(*current).name() == typeid(*a).name()))
			{
				Magazin* m = new Magazin(codul, current->getNume(), current->getPret(), current->getDataIntroducerii(), current->getNrExemplareDisponibile());
				repoMagazin->updateMagazin(m, mN);
				return 0;
			}		
			
		}
	}
	throw MyException("Codul introdus nu se afla in baza de date!!!");
}
vector<Magazin*> Service::get_All()
{
	return repoMagazin->getAll();
}
Service::~Service()
{

}
