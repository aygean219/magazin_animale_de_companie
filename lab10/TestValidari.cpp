#include "TestValidari.h"
#include "ValidatorAnimal.h"
#include "ValidatorException.h"
#include "ValidatorMagazin.h"
#include "ValidatorProdus.h"
#include <assert.h>
#include "animal_de_companie.h"
#include "magazin.h"
#include "produse_magazin.h"
TestValidator::TestValidator() {

}
TestValidator::~TestValidator()
{

}
void TestValidator::testAllValidator()
{
	testValidatorMagazin();
	testValidatorAnimal();
	testValidatorProdus();

}
void TestValidator::testValidatorMagazin() {
	ValidatorMagazin val;
	Magazin* m1 = new Magazin(1, "aa", 2, "12/2/2020", 3);
	try
	{
		val.validate(m1);
	}
	catch (...) {
		assert(false);
	}
	Magazin* m2 = new Magazin(-1, "aa", 2, "12/2/2020", 3);
	try
	{
		val.validate(m2);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Magazin* m3 = new Magazin(1, "", 2, "12/2/2020", 3);
	try
	{
		val.validate(m3);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Magazin* m4 = new Magazin(1, "aa", -2, "12/2/2020", 3);
	try
	{
		val.validate(m4);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Magazin* m5 = new Magazin(1, "aa", 2, "42/2/2020", 3);
	try
	{
		val.validate(m5);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	Magazin* m6= new Magazin(1, "aa", 2, "12/2/2020", -3);
	try
	{
		val.validate(m6);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete m5;
	delete m6;
}
void TestValidator::testValidatorAnimal()
{
	ValidatorAnimal val;
	Animal* a1 = new Animal(1, "aa", 2, "12/2/2020", 3, 4);
	try
	{
		val.validate(a1);
	}
	catch (...) {
		assert(false);
	}
	Animal* a2 = new Animal(1, "aa", 2, "12/2/2020", 3,-4);
	try
	{
		val.validate(a2);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	delete a1;
	delete a2;
}
void TestValidator::testValidatorProdus()
{
	ValidatorProdus val;
	Produs* p1 = new Produs(1, "aa", 2, "12/2/2020", 3, "23/12/2000");
	try
	{
		val.validate(p1);
	}
	catch (...) {
		assert(false);
	}
	Produs* p2 = new Produs(1, "aa", 2, "12/2/2020", 3, "32/12/2000");
	try
	{
		val.validate(p2);
		assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
	delete p1;
	delete p2;
}