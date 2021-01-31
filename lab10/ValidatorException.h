#pragma once
#include <exception>
#include <string.h>

using namespace std;

class ValidationException : public exception {
private:
	 char* message;
public:
	ValidationException(const char* m)
	{
		this->message = new char[strlen(m) + 1];
		strcpy_s(this->message, strlen(m) + 1, m);
	}

	~ValidationException()
	{
		if (this->message != NULL)
		{
			delete[] this->message;
		}
	}

	virtual const char* what()
	{
		return message;
	}
};