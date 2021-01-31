#include <string>
#include <exception>
#ifndef MYEXCEPTION2_H
#define MYEXCEPTION2_H

class MyException2:public std::exception {
private:
	const char* message1;
	const char* message2;
public:
	MyException2(const char* m1,const char*m2 ) : message1(m1),message2(m2){
	}
	std::string getMessage2() {
		std::string a = message1;
		std::string b = message2;
		return a+b;
	}
};
#endif
//class Animal
// class