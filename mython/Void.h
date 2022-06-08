#ifndef VOID_H
#define VOID_H

#include "type.h"
#include <iostream>
#include <string>


class Void : public Type
{
public:
	Void();
	~Void();

	bool isPrintable() const;
	std::string ToString() const;

};


#endif // VOID_H