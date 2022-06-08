#include "String.h"

String::String(char * value) : Sequence()
{
	this->value = std::string(value);
}

String::String(std::string value)
{
	this->value = value;
}

String::~String()
{

}

bool String::isPrintable() const
{
	return true;
}

std::string String::ToString() const
{
	return this->value;
}
