
#include "TesteLive12.h"
#include <assert.h>
#include "my_exception.h"
#include "exceptii2.h"
#include "exceptii3.h"
#include "produse_magazin.h"
#include "animal_de_companie.h"
#include "RepoFileTxt.h"
#include "RepoFileCsv.h"
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;
TestLive12::TestLive12()
{

}
TestLive12::~TestLive12()
{

}
void TestLive12::test()
{	
	RepoFile* repoFileTxt = new RepoFileTxt(fileNameInTxt);
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Animal* a1 = new Animal(554, "papagal", 100, "1/4/2020", 5,2 );
	Produs* a2 = new Produs(554, "mancare_pesti", 30, "11/12/2019", 12, "1/1/2022");
	Animal* a3 = new Animal(555, "papagal", 60, "3/5/2020", 3, 1);
	Animal* a4 = new Animal(554, "papagal", 70, "7/3/2020", 3, 3);
	Produs* a5 = new Produs(554, "mancare_pesti", 30, "11/12/2019", 20, "1/1/2022");
	serv.add2(a1);
	serv.add2(a2);
	serv.add2(a3);
	
	assert(serv.get_size() == 3);
	assert(*(serv.get_All()[0]) == *a1);
	assert(*(serv.get_All()[1]) == *a2);
	assert(*(serv.get_All()[2]) ==*a3);
	serv.add2(a4);
	assert(serv.get_size() == 3);
	assert(serv.get_All()[0]->getCod() == a1->getCod());
	assert(serv.get_All()[0]->getNume() == a1->getNume());
	assert(serv.get_All()[0]->getNrExemplareDisponibile() == 8);
	assert(*(serv.get_All()[1])== *a2);
	assert(*(serv.get_All()[2]) == *a3);
	////DACA APELEZI DE MAI MULTE ORI TE ROG STERGE DIN FISIER :)))
	
/*
	serv.add2(a5);
	assert(serv.get_size() == 3);
	assert(serv.get_All()[0]->getCod() == a1->getCod());
	assert(serv.get_All()[0]->getNume() == a1->getNume());
	assert(serv.get_All()[0]->getNrExemplareDisponibile() == 8);
	assert(serv.get_All()[0]->getCod() == a2->getCod());
	assert(serv.get_All()[0]->getNume() == a2->getNume());
	assert(serv.get_All()[0]->getNrExemplareDisponibile() == 32);
	assert(*(serv.get_All()[2]) == *a3);
	*/
	
}
void TestLive12::testAllL12()
{
	test();
}