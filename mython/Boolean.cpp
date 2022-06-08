#include "Boolean.h"


Boolean::Boolean(bool value) : Type()
{
	this->value = value;
}

Boolean::~Boolean()
{

}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::ToString() const
{
	if (this->value == true)
		return std::string("True");
	else
		return std::string("False");
}
