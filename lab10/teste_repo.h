#pragma once
#include "RepoFile.h"
class TestRepoFile {
private:
	const string fileNameInTxt = "TestMagazinInTxt.txt";
	const string fileNameOutTxt = "TestMagazinOutTxt.txt";
	const string fileNameInCsv = "TestMagazinInCsv.csv";
	const string fileNameOutCsv= "TestMagazinOutCsv.csv";
	vector<Magazin*> magazinIn;
	void testGetSize();
	void testGetAll();
	void testGetMagazin();
	void testAddMagazin();
	void testUpdateMagazin();
	void testDeleteMagazin();
	
	
	void testLoadFromFileTxt();
	void testLoadFromFileCsv();
	void testSaveToFileTxt();
	void testSaveToFileCsv();

public:
	TestRepoFile();
	~TestRepoFile();
	void testAll();

};