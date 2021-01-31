#include <exception>
#ifndef MYEXCEPTION3_H
#define MYEXCEPTION3_H

class MyException:public std::exception {
private:
	const char* message;
public:
	MyException(const char* m) : message(m) {
	}
	const char* getMessage() {
		return message;
	}
};
#endif