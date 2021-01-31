#include "animal_de_companie.h"
#include "magazin.h"
#include "produse_magazin.h"
#include "teste_clase.h"
#include "teste_repo.h"
#include "RepoFile.h"
#include "RepoFileCsv.h"
#include "RepoFileCsv.h"
#include "user.h"
#include "repo_in_memory.h"
#include "teste_repo_memory.h"
#include <iostream>
#include "Service.h"
#include "user.h"
#include "ui.h"
#include "teste_service.h"
#include "teste_live_11.h"
#include "TestValidari.h"
#include "TesteLive12.h"
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "Start...." << endl;
	TesteClase t;
	t.testClase();
	cout << "Test_clase...." << endl;
	TestRepoFile r;
	r.testAll();
	cout << "Test_repo_file...." << endl;
	TestRepoM m;
	m.testAllU();
	cout << "Test_repo_in_memory...." << endl;
	TestService s;
	s.testAllS();
	cout << "Test_service..." << endl;
	TestValidator v;
	v.testAllValidator();
	cout << "Test_validatori..." << endl;
	//TestLive12 tl;
	//tl.testAllL12();
	cout << "Stop....." << endl;
	RepoFile* repoFile;
	Service serv;
	UI ui(serv);
	ui.showMenu();
	cout << "Stop....." << endl;
	return 0;


}