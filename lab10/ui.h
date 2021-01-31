#pragma once
#include <string>
#include "Service.h"
using namespace std;
class UI {
private:
	Service serv;
	User u;
	void prop1();
	void prop2();
	void addAnimal();
	void addProdus();
	void delAnimal();
	void delProdus();
	void updAnimal();
	void updProdus();
	int login();
	void logout();
	void showAll();
	void fisier();
	void animal();
	void produs();
public:
	UI();
	~UI();
	void showMenu();
	UI(Service&);
};