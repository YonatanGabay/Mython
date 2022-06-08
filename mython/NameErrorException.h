#ifndef NAME_ERROR_EXCEPTION_H
#define NAME_ERROR_EXCEPTION_H

#include "InterperterException.h"
#include <iostream>
#include <string>

class NameErrorException : public InterperterException
{
private:
	std::string _exception;

public:
	virtual const char* what() const throw();
	void mekeException(std::string name);
};

#endif // NAME_ERROR_EXCEPTION_H
