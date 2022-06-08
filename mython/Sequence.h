#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "type.h"

class Sequence : public Type
{
public:
	Sequence();
	~Sequence();

	virtual bool isPrintable() const = 0;
	virtual std::string ToString() const = 0;
};


#endif // SEQUENCE_H