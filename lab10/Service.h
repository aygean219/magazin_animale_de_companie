#pragma once
#include "repo_in_memory.h"
#include "RepoFileCsv.h"
#include "RepoFileTxt.h"
#include "RepoFile.h"
#include "magazin.h"
#include "animal_de_companie.h"
#include "produse_magazin.h"
#include "user.h"
#include <vector>
class Service
{
private:
	RepoFile* repoMagazin;
	RepoUser* repoUsers;
public:
	Service();
	Service(RepoFile*, RepoUser*);
	void setRepoUser(RepoUser*);
	void setRepoFile(RepoFile*);
	void repoInit(string);
	void cumparare(int, int);
	vector<Magazin*> find_by_name(string );
	vector<Magazin*> find_by_date(string );
	void usersInit(RepoUser*);
	void insertt(int, Magazin*);
	void add(Magazin*);
	void add2(Magazin*);
	int deletee(int,Magazin*);
	int update(int, Magazin*,Magazin*);
	bool login(string, string);
	void logout(string, string);
	vector<Magazin*> get_All();
	int get_size();
	~Service();

};