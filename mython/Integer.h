#ifndef INTEGER_H
#define INTEGER_H

#include "type.h"
#include <iostream>
#include <string>

class Integer : public Type
{
public:
	int value;

	Integer(int value);
	~Integer();

	bool isPrintable() const;
	std::string ToString() const;
};


#endif // INTEGER_H