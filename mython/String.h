#ifndef STRING_H
#define STRING_H

#include "Sequence.h"
#include <iostream>
#include <string>

class String : public Sequence
{
public:
	std::string value;

	String(char* value);
	String(std::string value);
	~String();

	bool isPrintable() const;
	std::string ToString() const;

};


#endif // STRING_H