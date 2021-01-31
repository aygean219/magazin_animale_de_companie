#include "user.h"
#include <assert.h>
#include <iostream>
#include "repo_in_memory.h"
#include "teste_repo_memory.h"
using namespace std;
TestRepoM::TestRepoM()
{
	User* u1 = new User("aaa", "bbb");
	User* u2 = new User("ccc", "ddd");
	this->users.push_back(u1);
	this->users.push_back(u2);
}
TestRepoM::~TestRepoM()
{

}
void TestRepoM::testAdd()
{
	RepoUser* repo = new RepoUser();
	User* u1 = new User("a", "b");
	repo->addUser(u1);
	assert(*repo->getUser(0) == *u1->clone());
}
void TestRepoM::testUpd()
{
	RepoUser* repo = new RepoUser();
	User* u1 = new User("a", "b");
	repo->addUser(u1);
	User* u2 = new User("c", "d");
	User* u3 = new User("e", "f");
	repo->updateUser(u1, u2);
	assert(*repo->getUser(0) == *u2);
	repo->updateUser(u2, u3);
	assert(*repo->getUser(0) == *u3);

}
void TestRepoM::testDel()
{
	RepoUser* repo = new RepoUser();
	User* u1 = new User("a", "b");
	repo->addUser(u1);
	assert(repo->getSize() == 1);
	repo->deleteUser(u1);
	assert(repo->getSize() == 0);
}
void TestRepoM::testAllU()
{
	this->testAdd();
	this->testDel();
	this->testUpd();
}