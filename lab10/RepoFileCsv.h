#pragma once
#include "RepoFile.h"

class RepoFileCsv : public RepoFile {
public:
	RepoFileCsv();
	RepoFileCsv(string fileName);
	~RepoFileCsv();
	void loadFromFile();
	void saveToFile();
};