#include "Void.h"

Void::Void() : Type()
{

}

Void::~Void()
{

}

bool Void::isPrintable() const
{
	return false;
}

std::string Void::ToString() const
{
	return std::string("");
}
