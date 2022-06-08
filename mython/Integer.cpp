#include "Integer.h"


Integer::Integer(int value) : Type()
{
	this->value = value;
}

Integer::~Integer()
{

}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::ToString() const
{
	return std::string(std::to_string(this->value));
}
