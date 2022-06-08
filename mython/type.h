#ifndef TYPE_H
#define TYPE_H

#include <iostream>

class Type
{
private:
	bool _isTemp;

public:
	Type();
	~Type();

	bool Type::getIsTemp();
	void Type::setIsTemp(bool isTemp);

	virtual bool isPrintable() const = 0;
	virtual std::string ToString() const = 0;
};





#endif //TYPE_H
