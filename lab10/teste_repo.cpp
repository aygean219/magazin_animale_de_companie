#include <assert.h>
#include "teste_repo.h"
#include "produse_magazin.h"
#include "animal_de_companie.h"
#include "RepoFileTxt.h"
#include "RepoFileCsv.h"
#include <iostream>
using namespace std;

void TestRepoFile::testGetSize()
{
	RepoFile* repoFile = new RepoFileTxt();
	assert(repoFile->getSize() == 0);
	repoFile->addMagazin(new Magazin());
	assert(repoFile->getSize() == 1);
}
void TestRepoFile::testGetAll()
{
	RepoFile* repoFile = new RepoFileTxt();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Animal* p2 = new Animal(2, "papagal", 20, "19/03/2020", 4, 2);
	repoFile->addMagazin(p1);
	repoFile->addMagazin(p2);
	vector<Magazin*> magazinul = repoFile->getAll();
	assert(*magazinul[0] == *p1);
	assert(*magazinul[1] == *p2);
}
void TestRepoFile::testGetMagazin()
{
	RepoFile* repoFile = new RepoFileTxt();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	repoFile->addMagazin(p1);
	assert(*repoFile->getMagazin(0) == *p1->clone());
	assert(*repoFile->getMagazin(-1) == *(new Produs()));
	assert(*repoFile->getMagazin(1) == *(new Produs()));
}
void TestRepoFile::testAddMagazin()
{
	RepoFile* repoFile = new RepoFileTxt();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	repoFile->addMagazin(p1);
	assert(*repoFile->getMagazin(0) == *p1->clone());
}
void TestRepoFile::testUpdateMagazin()
{
	RepoFile* repoFile = new RepoFileTxt();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	repoFile->addMagazin(p1);
	Produs* p2 = new Produs(2, "bobite", 33, "20/12/2020", 14, "13/12/2023");
	Produs* p3 = new Produs(3, "apa", 22, "05/04/2020", 2, "24/03/2020");
	repoFile->updateMagazin(p1, p2);
	assert(*repoFile->getMagazin(0) == *p2);
	repoFile->updateMagazin(p2, p3);
	assert(*repoFile->getMagazin(0) == *p3);

}
void TestRepoFile::testDeleteMagazin()
{
	RepoFile* repoFile = new RepoFileTxt();
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	repoFile->addMagazin(p1);
	assert(repoFile->getSize() == 1);
	repoFile->deleteMagazin(p1);
	assert(repoFile->getSize() == 0);
}
void TestRepoFile::testLoadFromFileTxt()
{
	RepoFile* repoFile = new RepoFileTxt(this->fileNameInTxt);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->magazinIn.size());
	assert(*repoFile->getMagazin(0) == *this->magazinIn[0]);
	assert(*repoFile->getMagazin(1) == *this->magazinIn[1]);
}
void TestRepoFile::testLoadFromFileCsv()
{
	RepoFile* repoFile = new RepoFileCsv(this->fileNameInCsv);
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->magazinIn.size());
	assert(*repoFile->getMagazin(0) == *this->magazinIn[0]);
	assert(*repoFile->getMagazin(1) == *this->magazinIn[1]);
	
}
void TestRepoFile::testSaveToFileTxt()
{
	RepoFile* repoFile = new RepoFileTxt(this->fileNameInTxt);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutTxt);
	Animal* newA = new Animal(3, "caine", 20, "12/04/2020", 2, 5);
	repoFile->addMagazin(newA);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->magazinIn.size() + 1);
	vector<Magazin*> magazinul = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*magazinul[i] == *this->magazinIn[i]);
	}
	assert(*magazinul[magazinul.size() - 1] == *newA);
}
void TestRepoFile::testSaveToFileCsv()
{
	RepoFile* repoFile = new RepoFileCsv(this->fileNameInCsv);
	repoFile->loadFromFile();
	repoFile->setFileName(this->fileNameOutCsv);
	Animal* newA = new Animal(3, "caine", 20, "12/04/2020", 2, 5);
	repoFile->addMagazin(newA);
	repoFile->saveToFile();
	repoFile->loadFromFile();
	assert(repoFile->getSize() == this->magazinIn.size() + 1);
	vector<Magazin*> magazinul = repoFile->getAll();
	for (int i = 0; i < repoFile->getSize() - 1; i++)
	{
		assert(*magazinul[i] == *this->magazinIn[i]);
	}
	assert(*magazinul[magazinul.size() - 1] == *newA);
	
}
TestRepoFile::TestRepoFile()
{
	Produs* p1 = new Produs(1, "mancare", 40, "19/02/2019", 23, "14/12/2030");
	Animal* p2=new Animal(2, "papagal", 20, "19/03/2020", 4, 2);
	this->magazinIn.push_back(p1);
	this->magazinIn.push_back(p2);
}

TestRepoFile::~TestRepoFile()
{
}

void TestRepoFile::testAll()
{
	this->testGetSize();
	this->testGetAll();
	this->testGetMagazin();
	this->testAddMagazin();
	this->testUpdateMagazin();
	this->testDeleteMagazin();
	this->testLoadFromFileTxt();
	this->testLoadFromFileCsv();
	this->testSaveToFileTxt();
	this->testSaveToFileCsv();
}
