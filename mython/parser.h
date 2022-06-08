#ifndef PARSER_H
#define PARSER_H

#include "InterperterException.h"
#include "type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

class Parser
{
public:
	static std::unordered_map<std::string, Type*> _variables;

	static Type* parseString(std::string str) throw();
	static Type* getType(std::string &str);

private:

	static bool isLegalVarName(const std::string& str);
	static bool makeAssignment(const std::string& str);
	static Type* getVariableValue(const std::string &str);


};

#endif //PARSER_H
