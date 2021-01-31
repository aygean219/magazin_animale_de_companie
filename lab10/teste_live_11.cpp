#include "teste_live_11.h"
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
TestLive::TestLive()
{

}
TestLive::~TestLive()
{

}
void TestLive::test()
{
	RepoFile* repoFileTxt = new RepoFileTxt(fileNameInTxt);
	RepoUser* repo_user = new RepoUser();
	User* u = new User("aa", "bb");
	repo_user->addUser(u);
	Service serv(repoFileTxt, repo_user);
	serv.setRepoFile(repoFileTxt);
	serv.repoInit(fileNameInTxt);
	Animal* a1=new Animal(554, "papagal", 100, "01.04.2020", 2, 5);
	Produs* a2=new Produs(361, "mancare_pesti", 30, "11.12.2019", 12,"01.01.2022");
	Animal* a3=new Animal(409, "hamster", 60, "03.05.2020", 1, 3);
	Animal* a4=new Animal(104, "canar", 70, "07.03.2020", 3, 1);
	Produs* a5 = new Produs(361, "crema_purici", 15, "02.01.2020", 40, "01.01.2023");
	serv.add(a1);
	serv.add(a2);
	try {
		serv.insertt(1, a3);
		assert(serv.get_size() == 3);
		assert(*(serv.get_All()[0]) == *a1);
		assert(*(serv.get_All()[1]) == *a3);
		assert(*(serv.get_All()[2]) == *a2);

	}
	catch (MyException& ex1)
	{
		assert(false);
	}
	catch (MyException22& ex2)
	{
		assert(false);
	}
	catch (MyException3& ex3)
	{
		assert(false);
	}
	try {
		serv.insertt(4, a4);
		assert(false);
	}
	catch (MyException& ex1)
	{
		cout << "InsertException1 thrown" << endl;
		assert(serv.get_size() == 3);
		assert(*(serv.get_All()[0]) == *a1);
		assert(*(serv.get_All()[1]) == *a3);
		assert(*(serv.get_All()[2]) == *a2);


	}
	catch (MyException22& ex2)
	{
		assert(false);
	}
	catch (MyException3& ex3)
	{
		assert(false);
	}
	try {
		serv.insertt(1, a5);
		assert(false);
	}
	catch (MyException& ex1)
	{
		assert(false);
	}
	catch (MyException22& ex2)
	{
		cout << "InsertException2 thrown" << endl;
		assert(serv.get_size() == 3);
		assert(*(serv.get_All()[0]) == *a1);
		assert(*(serv.get_All()[1]) == *a3);
		assert(*(serv.get_All()[2]) == *a2);
	}
	catch (MyException3& ex3)
	{
		assert(false);
	}
	
	try {
		serv.insertt(4, a4);
		assert(false);
	}
	catch (MyException& ex1)
	{
		assert(false);
	}
	catch (MyException22& ex2)
	{
		assert(false);
	}
	catch (MyException3& ex3)
	{
		cout << "InsertException3 thrown" << endl;
	}
	try {
		serv.insertt(1, a5);
		assert(false);
	}
	catch (MyException& ex1)
	{
		assert(false);
	}
	catch (MyException22& ex2)
	{
		assert(false);
	}
	catch (MyException3& ex3)
	{
		cout << "InsertException3 thrown" << endl;
	}
}
void TestLive::testAllL()
{
	test();
}