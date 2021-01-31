#include "my_exception.h"
#include "exceptii2.h"
#include "my_exception2.h"
#include <stdlib.h>
#include <typeinfo>
#include "ui.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ValidatorException.h"
using namespace std;
UI::UI()
{

}
UI::UI(Service& s)
{
	serv = s;
}
void UI::prop1()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout << "Va rugam alegeti dupa ce doriti sa cautati: " << endl;
	string nume, date;
	int opt;
	cout << "1.Dupa nume;" << endl;
	cout << "2.Dupa data introducerii;" << endl;
	cout << "Optiunea: "; cin >> opt;
	if (opt == 1)
	{
		cout << "Dati numele pe care doriti sa-l cautati: "; cin >> nume;
		try {
			vector<Magazin*> m=serv.find_by_name(nume);
			Animal* a = new Animal();
			for (Magazin* current : m)
			{
				if ((typeid(*current).name() == typeid(*a).name()))
				{
					cout << "Animal-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Varsta: " << ((Animal*)current)->getVarsta() << endl;
				}
				else
				{
					cout << "Produs-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Data exp: " << ((Produs*)current)->getDataExpirarii() << endl;
				}

			}

		}
		catch (MyException& exc1)
		{
			cout << "Eroare: " << exc1.getMessage() << endl;
		}
		catch (ValidationException& ex3)
		{
			cout << "Eroare la validari: " << ex3.what() << endl;
		}

	}
	if (opt == 2)
	{
		cout << "Dati data pe care doriti sa o cautati: "; cin >> date;
		try {
			vector<Magazin*> mm = serv.find_by_date(date);
			Animal* a = new Animal();
			for (Magazin* current :mm)
			{
				if ((typeid(*current).name() == typeid(*a).name()))
				{
					cout << "Animal-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Varsta: " << ((Animal*)current)->getVarsta() << endl;
				}
				else
				{
					cout << "Produs-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Data exp: " << ((Produs*)current)->getDataExpirarii() << endl;
				}

			}

		}
		catch (ValidationException& ex3)
		{
			cout << "Eroare la validari: " << ex3.what() << endl;
		}
		catch (MyException& exc1)
		{
			cout << "Eroare: " << exc1.getMessage() << endl;
		}
		
	}
}
void UI::prop2()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	showAll();
	int cod, numar;
	cout << "Dati codul pe care l doriti: "; cin >> cod;
	cout << endl << "Dati numarul de exemplare : "; cin >> numar;
	try {
		serv.cumparare(cod, numar);
		cout << "S-a realizat cumpararea!!" << endl;
	}
	catch (MyException& ex1)
	{
		cout << "Eroare: " << ex1.getMessage() << endl;
	}
	catch (MyException22& ex2)
	{
		cout << "Eroare: " << ex2.getMessage() << endl;
	}
	catch (ValidationException& ex3)
	{
		cout << "Eroare la validari: " << ex3.what() << endl;
	}
}
void UI::addAnimal()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout << "Animalul de companie:" << endl;
	string nume, data_introducerii;
	int cod, pret, varsta, nr_exemplare;
	cout << "Dati codul: ";
	cin >> cod;
	cin.ignore();
	cout << "Dati numele: ";
	getline(cin, nume);
	//cin >> nume;
	//std::getline(std::cin, nume);
	cout << "Dati pretul: ";
	cin >> pret;
	cout << "Dati data introducerii:";
	cin >> data_introducerii;
	cout << "Dati varsta: ";
	cin >> varsta;
	cout << "Dati numarul de exemplare: ";
	cin >> nr_exemplare;
	Animal* a=new Animal(cod, nume, pret, data_introducerii, nr_exemplare, varsta);
	try {
		serv.add(a);
		cout << "Animalul de companie a fost introdus cu succes!!" << endl;
	}
	catch (MyException& exc) {
		cout << "Eroare: " << exc.getMessage() << endl;
	}
	catch (ValidationException & ex)
	{
		cout << "Eroare la validari: " << ex.what() << endl;
	}
	
}
void UI::addProdus()
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout << "Produsul :" << endl;
	string nume, data_introducerii, data_expirarii;
	int cod, pret, nr_exemplare;
	cout << "Dati codul: ";
	cin >> cod;
	cin.ignore();
	cout << "Dati numele: ";
	//cin >> nume;
	getline(cin, nume);
	cout << "Dati pretul: ";
	cin >> pret;
	cout << "Dati data introducerii:";
	cin >> data_introducerii;
	cout << "Dati numarul de exemplare: ";
	cin >> nr_exemplare;
	cout << "Dati data expirarii: ";
	cin >> data_expirarii;
	Produs* p=new Produs(cod, nume, pret, data_introducerii, nr_exemplare, data_expirarii);
	try {
		serv.add(p);
		cout << "Produsul a fost introdus cu succes!!" << endl;
	}
	catch (ValidationException& ex)
	{
		cout << "Eroare la validari: " << ex.what() << endl;
	}
	catch (MyException& exc) {
		cout << "Eroare: " << exc.getMessage() << endl;
	}
	

}
void UI::updAnimal()
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	int codul;
	cout << "Dati codul animalului de companie pe care doriti sa-l modificati:  ";
	cin >> codul;
	string nume, data_introducerii;
	int cod, pret, varsta, nr_exemplare;
	cout << "Dati noul codul: ";
	cin >> cod;
	cin.ignore();
	cout << "Dati noul numele: ";
	getline(cin, nume);
	//cin >> nume;
	cout << "Dati noul pretul: ";
	cin >> pret;
	cout << "Dati noua data a introducerii:";
	cin >> data_introducerii;
	cout << "Dati noul numarul de exemplare: ";
	cin >> nr_exemplare;
	cout << "Dati noua varsta: ";
	cin >> varsta;
	Animal* a = new Animal(cod, nume, pret, data_introducerii, nr_exemplare, varsta);
	Animal* p = new Animal();
	try {
		int ok = serv.update(codul, a, p);
		if (ok == 0)
			cout << "Update-ul animalului de companie a fost realizat cu succes" << endl;
	}
	catch (MyException2& exc)
	{
		cout << "Eroare: " << exc.getMessage2() << endl;
	}
	catch (MyException& exc2)
	{
		cout << "Eroare:" << exc2.getMessage() << endl;
	}
	catch (ValidationException& ex)
	{
		cout << "Eroare la validari: " << ex.what() << endl;
	}
}
void UI::updProdus()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	int codul;
	cout << "Dati codul produsului pe care doriti sa-l modificati:  ";
	cin >> codul;
	string nume, data_introducerii, data_expirarii;
	int cod, pret, varsta, nr_exemplare;
	cout << "Dati noul codul: ";
	cin >> cod;
	cin.ignore();
	cout << "Dati noul numele: ";
	getline(cin, nume);
	cout << "Dati noul pretul: ";
	cin >> pret;
	cout << "Dati noua data a introducerii:";
	cin >> data_introducerii;
	cout << "Dati noul numarul de exemplare: ";
	cin >> nr_exemplare;
	cout << "Dati noua data a expirarii:";
	cin >> data_expirarii;
	Produs* p = new Produs(cod, nume, pret, data_introducerii, nr_exemplare, data_expirarii);
	Produs* a = new Produs();
	try {
		int ok = serv.update(codul, p, a);
		if (ok == 0)
			cout << "Update-ul produsului a fost realizat cu succes" << endl;
	}
	catch (MyException2& exc)
	{
		cout << "Eroare: " << exc.getMessage2() << endl;
	}
	catch (MyException& exc2)
	{
		cout << "Eroare:" << exc2.getMessage() << endl;
	}
	catch (ValidationException& ex)
	{
		cout << "Eroare la validari: " << ex.what() << endl;
	}
}
void UI::delAnimal() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	int codul;
	cout << "Dati codul animalului de companie pe care doriti sa-l stergeti: " << endl;
	cin >> codul;
	Animal* a = new Animal();
	try {
		int ok = serv.deletee(codul, a);
		if (ok == 0)
			cout << "A avut loc stergerea cu succes a animalului de companie!!" << endl;
		else
			cout << "Nu s-a realizat stergerea animalului de companie!!" << endl;
	}
	catch (MyException2& exc)
	{
		cout << "Eroare: " << exc.getMessage2()<<endl;
	}
	catch (MyException& exc2)
	{
		cout << "Eroare:" << exc2.getMessage() << endl;
	}
}
void UI::delProdus()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	int codul;
	cout << "Dati codul produsului pe care doriti sa-l stergeti: " << endl;
	cin >> codul;
	try {
	Produs* a = new Produs();
	int ok = serv.deletee(codul,a);
	if (ok == 0)
		cout << "A avut loc stergerea cu succes a produsului!!" << endl;
	else
		cout << "Nu s-a realizat stergerea produsului!!" << endl;
	}
	catch (MyException2& exc)
	{
		cout << "Eroare: " << exc.getMessage2() << endl;
	}
	catch (MyException& exc2)
	{
		cout << "Eroare:" << exc2.getMessage() << endl;
	}
}
int UI::login()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout << "Buna ziua si bine ati venit :)!!" << endl;
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);
	cout << "Dati user:";
	cin >> user;
	cout << endl << "Parola:";
	cin >> pass;
	return serv.login(user, pass);
}
void UI::showAll()
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),116);
	vector<Magazin*> all = serv.get_All();
	Animal* a = new Animal();
	for (Magazin* current : all)
	{
		int ok1 = 0, ok2 = 0;
		if (current->getNrExemplareDisponibile() == 0)
		{
			if ((typeid(*current).name() == typeid(*a).name()))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 196);
				cout << "Animal-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Varsta: " << ((Animal*)current)->getVarsta() << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 196);
				cout << "Produs-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Data exp: " << ((Produs*)current)->getDataExpirarii() << endl;
			}
		}
		else
		{
			if ((typeid(*current).name() == typeid(*a).name()))
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
				cout << "Animal-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Varsta: " << ((Animal*)current)->getVarsta() << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
				cout << "Produs-->Cod: " << current->getCod() << ",Nume: " << current->getNume() << ",Pret: " << current->getPret() << ",Data In: " << current->getDataIntroducerii() << ",Nr: " << current->getNrExemplareDisponibile() << ",Data exp: " << ((Produs*)current)->getDataExpirarii() << endl;
			}
		}
	}
}
void UI::animal()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	int m = 1;
	bool gata1 = false;
	while (!gata1)
	{
		cout << "a.Adaugare animal de companie" << endl;
		cout << "b.Update animal de companie dupa cod" << endl;
		cout << "c.Stergere animal de companie dupa cod" << endl;
		cout << "d.Afisare toate elementele" << endl;
		cout << "e.Intoarcere la meniul principal" << endl;
		char opt;
		cout << "Dati optiunea: " << endl;
		cin >> opt;
		switch (opt)
		{
		case 'a': {addAnimal(); break; }
		case 'b': {updAnimal(); break; }
		case 'c': {delAnimal(); break; }
		case 'd': {showAll(); break; }
		case 'e': { gata1 = true; }
		}

	}

}
void UI::produs()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int m = 1;
	bool gata1 = false;
	while (!gata1)
	{
		cout << "a.Adaugare produs pentru animal de companie" << endl;
		cout << "b.Update produs pentru animal de companie dupa cod" << endl;
		cout << "c.Stergere produs pentru animal de companie dupa cod" << endl;
		cout << "d.Afisare toate elementele" << endl;
		cout << "e.Intoarcere la meniul principal" << endl;
		char opt;
		cout << "Dati optiunea: " << endl;
		cin >> opt;
		switch (opt)
		{
		case 'a': {addProdus(); break; }
		case 'b': {updProdus(); break; }
		case 'c': {delProdus(); break; }
		case 'd': {showAll(); break; }
		case 'e': { gata1 = true; }
		}

	}
}
void UI::logout()
{
	serv.logout(u.getUserName(), u.getPassword());
	
}
void UI::fisier()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	RepoFile* repoFile;
	RepoUser* repoUser = new RepoUser();
	serv.setRepoUser(repoUser);
	serv.usersInit(repoUser);
	const string fileNameInTxt = "MagazinInTxt.txt";
	const string fileNameInCsv = "MagazinInCsv.csv";
	cout << "Doriti sa lucrati cu TXT sau CSV?" << endl;
	string opt;
	cin >> opt;
	if (opt == "txt")
	{
		repoFile = new RepoFileTxt(fileNameInTxt);
		serv.setRepoFile(repoFile);
		serv.repoInit(fileNameInTxt);
	}
	else
	{
		if (opt == "csv")
		{
			repoFile = new RepoFileCsv(fileNameInCsv);
			serv.setRepoFile(repoFile);
			serv.repoInit(fileNameInCsv);
		}
	}
}
void UI::showMenu(){

	int k = 1;
	bool gata = false;
	fisier();
	int rez = login();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
	while (!gata) {
		if (rez != 0) {
			if (k < 15) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
				cout << "1.Optiunile pentru animale de companie" << endl;
				k++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
				cout << "2.Optiunile pentru produse pentru animale de companie" << endl;
				k++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
				cout << "3.Afisare toate elementele" << endl;
				k++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
				cout << "4.Cautare dupa nume sau dupa data introducerii" << endl;
				k++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
				cout << "5.Cumparare dupa cod si alegere numar de exemplare dorite" << endl;
				k++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
				cout << "6.Logout" << endl;
				k++;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
				cout << "Dati optiunea: " << endl;
				int opt;
				cin >> opt;
				k++;
				switch (opt) {
				case 1: {animal(); break; }
				case 2: {produs(); break; }
				case 3: {showAll(); break; }
				case 4: {prop1(); break; }
				case 5: {prop2(); break; }
				case 6: {
					
					fisier();
					rez = login();
					break; }
				case 0: { gata = true; }
				}

			}
			else { k = 1; }//sa nu ajunga la 16 se vede naspa
		}
		else {
			k++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
			cout << "Autentificare esuata!" << endl;
			cout << "Va rugam sa incercati iar sa va autentificati apasand tasta 0,daca nu doriti sa mai incercati apasati 1:";
			cin >> gata;
			if (gata == false)
				rez = login();
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "Ne pare rau ca nu v-am putut ajuta..Va dorim o zi frumoasa !!" << endl;
			}
		}
	}
}
UI::~UI()
{

}
