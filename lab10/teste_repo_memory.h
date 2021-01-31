#pragma once
#include "repo_in_memory.h"
class TestRepoM {
private:
	vector<User*> users;
	void testAdd();
	void testDel();
	void testUpd();
public:
	void testAllU();
	TestRepoM();
	~TestRepoM();

};