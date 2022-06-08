#include "NameErrorException.h"
#include <sstream>

const char * NameErrorException::what() const throw()
{
	return this->_exception.c_str();
}

void NameErrorException::mekeException(std::string name)
{
	// make the exception
	this->_exception = "NameError : name '" + name + "' is not defined";
}
