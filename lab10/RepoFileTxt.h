#pragma once
#include "RepoFile.h"
class RepoFileTxt :public RepoFile {
public:
	RepoFileTxt();
	RepoFileTxt(string fileName);
	~RepoFileTxt();
	void loadFromFile();
	void saveToFile();
};