#pragma once
#include "user.h"
#include <vector>
using namespace std;
class RepoUser {
private:
	vector<User*> users;
public:
	RepoUser();
	void addUser(User* u);
	int getSize();
	User* getUser(int pos);
	vector<User*> getAllU();
	int find(User*);
	void updateUser(User* uVechi, User* uNou);
	void deleteUser(User* u);
	~RepoUser();
};