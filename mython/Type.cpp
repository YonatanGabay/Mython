#include "type.h"


Type::Type()
{
	this->_isTemp = false;
}

Type::~Type()
{

}

bool Type::getIsTemp()
{
	return this->_isTemp;
}

void Type::setIsTemp(bool isTemp)
{
	this->_isTemp = isTemp;
}
