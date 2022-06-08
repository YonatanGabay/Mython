#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "type.h"
#include <iostream>
#include <string>

class Boolean : public Type
{
public:
	bool value;

	Boolean(bool value);
	~Boolean();

	bool isPrintable() const;
	std::string ToString() const;

};

#endif // BOOLEAN_H