#include <exception>
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

class MyException3 :public std::exception {
private:
	const char* message;
public:
	MyException3(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
#endif