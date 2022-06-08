#ifndef SYNTAX_EXCEPTION_H
#define SYNTAX_EXCEPTION_H
#include "IndentationException.h"


class SyntaxException : public IndentationException
{
public:
	virtual const char* what() const throw();
};

#endif // SYNTAX_EXCEPTION_H
