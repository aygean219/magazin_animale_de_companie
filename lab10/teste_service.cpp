#include <assert.h>
#include "my_exception.h"
#include "exceptii2.h"
#include "exceptii3.h"
#include "my_exception2.h"
#include "produse_magazin.h"
#include "animal_de_companie.h"
#include "RepoFileTxt.h"
#include "RepoFileCsv.h"
#include "ValidatorException.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include "teste_service.h"
using namespace std;
TestService::TestService()
{
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Animal* p2 = new Animal(2, "papagal", 20, "19/03/2020", 4, 2);
	this->magazin.push_back(p1);
	this->magazin.push_back(p2);
}

TestService::~TestService()
{
}

void TestService::testAllS()
{
	
	this->testAddMagazin();
	this->testUpdateMagazin();
	this->testDeleteMagazin();
	this->testcumparare();
	this->testFindByDate();
	this->testFindByName();
}
void TestService::testAddMagazin()
{
	RepoFile* repoFileTxt = new RepoFileTxt(fileNameInTxt);
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	assert(serv.get_size() == 0);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Produs* p = new Produs();
	Animal* aa = new Animal();
	Animal* p2 = new Animal(2, "papagal", 20, "19/03/2020", 4, 2);
	///Este adaugat size=1
	try {
		serv.add(p2);
		assert(serv.get_size() == 1);
	}
	catch (MyException& exc)
	{
		assert(false);
		//assert(strcmp(exc.getMessage(), "Codul exista deja!!!!") == 0);
	}
	//nu se adauga se prinde exceptia
	Animal* p3 = new Animal(2, "papagal", 20, "19/03/2020", 4, 2);
	try {
		serv.add(p3);
		assert(false);
		//assert(serv.get_size() == 1);
	}
	catch (MyException& exc)
	{
		assert(strcmp(exc.getMessage(), "Codul exista deja!!!!") == 0);
	}
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	//Este adaugat size=2
	try {
		serv.add(p1);
		assert(serv.get_size() == 2);
		//assert(false);
	}
	catch (MyException& exc)
	{
		//assert(strcmp(exc.getMessage(), "Codul exista deja!!!!") == 0);
		assert(false);
	}
	//este sters
	try {
		int ok = serv.deletee(1, p);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		std::string a = "Ati introdus codul unui obiect de tip:";
		std::string b = typeid(*aa).name();
		std::string c = a + b;
		assert(ex2.getMessage2() == c);
	}
	//este sters
	try {
		
		int ok = serv.deletee(2, aa);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2()=="Ati introdus codul unui obiect de tip: class Animal");
	}


}
void TestService::testDeleteMagazin()
{
	RepoFile* repoFileTxt = new RepoFileTxt();
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	assert(serv.get_size() == 0);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Produs* p = new Produs();
	Animal* aa = new Animal();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Produs* p2 = new Produs(2, "bobite", 33, "20/12/2020", 14, "13/12/2023");
	Produs* p3 = new Produs(3, "apa", 22, "05/04/2020", 2, "24/03/2020");
	Animal* p4 = new Animal(4, "papagal", 20, "19/03/2020", 4, 2);
	//add
	try {
		serv.add(p1);
		serv.add(p2);
		serv.add(p3);
		serv.add(p4);
		assert(serv.get_size() == 4);
	}
	catch (MyException& exc)
	{
		assert(false);
		assert(strcmp(exc.getMessage(), "Codul exista deja!!!!") == 0);
	}
	//delete cu succes animal
	try {
		int ok = serv.deletee(4, aa);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Animal");
	}
	//nu gaseste codul
	try {
		int ok = serv.deletee(5, aa);
		assert(ok == 0);
		assert(false);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Animal");
		assert(false);
	}
	//este produs
	try {
		int ok = serv.deletee(2, aa);
		assert(ok == 0);
		assert(false);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Produs");
	}
	
	//este sters
	try {
		int ok = serv.deletee(3, p);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Produs");
	}
	//este sters
	try {
		int ok = serv.deletee(2, p);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Produs");
	}
	//este sters
	try {
		int ok = serv.deletee(1, p);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Produs");
	}
}
void TestService::testUpdateMagazin()
{
	RepoFile* repoFileTxt = new RepoFileTxt();
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	assert(serv.get_size() == 0);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Produs* p = new Produs();
	Animal* aa = new Animal();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Produs* p2 = new Produs(2, "bobite", 33, "20/12/2020", 14, "13/12/2023");
	Produs* p3 = new Produs(3, "apa", 22, "05/04/2020", 2, "24/03/2020");
	Animal* p4 = new Animal(4, "papagal", 20, "19/03/2020", 4, 2);
	try {
		serv.add(p1);
		serv.add(p4);
		assert(serv.get_size() == 2);
	}
	catch (MyException& exc)
	{
		assert(false);
		assert(strcmp(exc.getMessage(), "Codul exista deja!!!!") == 0);
	}
	//succes
	try {
		int ok = serv.update(1, p2, p);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class	Produs");
	}
	//cod gresit
	try {
		int ok = serv.update(3, p2, p);
		assert(ok == 0);
		assert(false);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Produs");
	}
	//cod de animal
	try {
		int ok = serv.update(4, p3, p);
		assert(false);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Animal");
	}
	try {
		int ok = serv.deletee(2, p);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Produs");
	}
	try {
		int ok = serv.deletee(4, aa);
		assert(ok == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
		assert(strcmp(ex.getMessage(), "Codul introdus nu se afla in baza de date!!!") == 0);
	}
	catch (MyException2& ex2)
	{
		assert(false);
		assert(ex2.getMessage2() == "Ati introdus codul unui obiect de tip: class Animal");
	}
}
void TestService::testcumparare()
{
	RepoFile* repoFileTxt = new RepoFileTxt();
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	assert(serv.get_size() == 0);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Produs* p = new Produs();
	Animal* aa = new Animal();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Produs* p2 = new Produs(2, "bobite", 33, "20/12/2020", 14, "13/12/2023");
	Produs* p3 = new Produs(3, "apa", 22, "05/04/2020", 2, "24/03/2020");
	Animal* p4 = new Animal(4, "papagal", 20, "19/03/2020", 4, 2);
	serv.add(p1);
	serv.add(p2);
	serv.add(p3);
	serv.add(p4);
	try {
		serv.cumparare(1, 21);
		assert(serv.get_All()[0]->getNrExemplareDisponibile() == 2);
	}
	catch (MyException& ex1)
	{
		assert(false);
	}
	catch (MyException22& ex2)
	{
		assert(false);
	}
	try {
		serv.cumparare(7, 3);
		assert(false);
	}
	catch (MyException& ex1)
	{
		assert(strcmp(ex1.getMessage(), "Nu s-a gasit codul!!") == 0);
	}
	catch (MyException22& ex2)
	{
		assert(false);
	}
	try {
		serv.cumparare(1, 3);
		assert(false);
	}
	catch (MyException& ex1)
	{
		assert(false);
	}
	catch (MyException22& ex2)
	{
		assert(strcmp(ex2.getMessage(), "Numarul de exemplare introdus este prea mare")==0);
	}
	serv.deletee(1,p);
	serv.deletee(2, p);
	serv.deletee(3, p);
	serv.deletee(4,aa);

}

void TestService::testFindByDate()
{
	RepoFile* repoFileTxt = new RepoFileTxt();
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	assert(serv.get_size() == 0);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Produs* p = new Produs();
	Animal* aa = new Animal();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Produs* p2 = new Produs(2, "bobite", 33, "20/12/2020", 14, "13/12/2023");
	Produs* p3 = new Produs(3, "apa", 22, "05/04/2020", 2, "24/03/2020");
	Animal* p4 = new Animal(4, "papagal", 20, "20/12/2020", 4, 2);
	serv.add(p1);
	serv.add(p2);
	serv.add(p3);
	serv.add(p4);
	vector<Magazin*> v;
	v.push_back(p2);
	v.push_back(p4);
	try {
		vector<Magazin*> m=serv.find_by_date("20/12/2020");
		assert(m[0]->getNrExemplareDisponibile()==v[0]->getNrExemplareDisponibile());
		assert(m[1]->getNrExemplareDisponibile() == v[1]->getNrExemplareDisponibile());
	}
	catch (MyException& ex)
	{
		assert(false);
	}
	try {
		vector<Magazin*> m = serv.find_by_date("22/12/2020");
		assert(false);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Data nu exista!!")==0);
	}
	catch (ValidationException& e)
	{
		assert(false);
	}
	try {
		vector<Magazin*> m = serv.find_by_date("33/12/2020");
		assert(false);
	}
	catch (ValidationException& e)
	{
		assert(strcmp(e.what(), "Data trebuie sa fie una valida!!") == 0);
	}
	catch (MyException& ex)
	{
		assert(false);
	}
	
	serv.deletee(1, p);
	serv.deletee(2, p);
	serv.deletee(3, p);
	serv.deletee(4, aa);
}
void TestService::testFindByName()
{
	RepoFile* repoFileTxt = new RepoFileTxt();
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	assert(serv.get_size() == 0);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Produs* p = new Produs();
	Animal* aa = new Animal();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Produs* p2 = new Produs(2, "bobite", 33, "20/12/2020", 14, "13/12/2023");
	Produs* p3 = new Produs(3, "apa", 22, "05/04/2020", 2, "24/03/2020");
	Animal* p4 = new Animal(4, "papagal", 20, "20/12/2020", 4, 2);
	serv.add(p1);
	serv.add(p2);
	serv.add(p3);
	serv.add(p4);
	vector<Magazin*> v;
	v.push_back(p2);
	v.push_back(p4);
	try {
		vector<Magazin*> m = serv.find_by_date("20/12/2020");
		assert(m[0]->getNrExemplareDisponibile() == v[0]->getNrExemplareDisponibile());
		assert(m[1]->getNrExemplareDisponibile() == v[1]->getNrExemplareDisponibile());
	}
	catch (MyException& ex)
	{
		assert(false);
	}
	try {
		vector<Magazin*> m = serv.find_by_date("22/12/2020");
		assert(false);
	}
	catch (MyException& ex)
	{
		assert(strcmp(ex.getMessage(), "Data nu exista!!") == 0);
	}
	serv.deletee(1, p);
	serv.deletee(2, p);
	serv.deletee(3, p);
	serv.deletee(4, aa);
}