#pragma once
#include "Service.h"
class TestService {
private:
	const string fileNameInTxt = "TestMagazinInTxtS.txt";
	const string fileNameOutTxt = "TestMagazinOutTxtS.txt";
	const string fileNameInCsv = "TestMagazinInCsvS.csv";
	const string fileNameOutCsv = "TestMagazinOutTxtS.csv";
	vector<Magazin*> magazin;
	void testFindByDate();
	void testFindByName();
	void testcumparare();
	void testAddMagazin();
	void testUpdateMagazin();
	void testDeleteMagazin();
public:
	TestService();
	~TestService();
	void testAllS();

};