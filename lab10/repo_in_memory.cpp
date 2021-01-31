#include "repo_in_memory.h"
RepoUser::RepoUser()
{
}
RepoUser::~RepoUser()
{
}
int RepoUser::getSize()
{
	return this->users.size();
}
void RepoUser::addUser(User* u)
{
	this->users.push_back(u->clone());
}
User* RepoUser::getUser(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->users[pos]->clone();
	}
	return new User();
}
int RepoUser::find(User* u)
{
	int k = this->users.size();
	for (int i = 0; i < k; i++)
	{
		if (*(this->getUser(i)) == *u)
			return 0;
	}
	return - 1;
}
void RepoUser::updateUser(User* uVechi, User* uNou)
{
	int k = this->users.size();
	for (int i = 0; i < k; i++)
	{
		if (*(this->getUser(i)) == *uVechi)
		{
			delete this->users[i];
			this->users[i] = uNou->clone();
			return;
		}
	}
}
vector<User*> RepoUser::getAllU()
{
	return this->users;
}
void RepoUser::deleteUser(User* u)
{
	int k = this->users.size();
	for (int i = 0; i < k; i++)
	{
		if (**(this->users.begin() + i) == *u)
		{
			delete this->users[i];
			this->users.erase(this->users.begin() + i);
			return;
		}
	}
}