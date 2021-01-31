#include <exception>
#ifndef MYEXCEPTION22_H
#define MYEXCEPTION22_H

class MyException22 :public std::exception {
private:
	const char* message;
public:
	MyException22(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
#endif