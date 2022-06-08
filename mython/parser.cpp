#include "parser.h"
#include <iostream>
#include <string>
#include "Helper.h"
#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "InterperterException.h"
#include "IndentationException.h"
#include "NameErrorException.h"
#include "SyntaxException.h"

std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str) throw()
{
	Type* variable = nullptr;

	if (str[0] == ' ')
		throw new IndentationException();

	if (!makeAssignment(str)) // try make assignment
	{
		if (isLegalVarName(str)) // if is valid var name
		{
			variable = getVariableValue(str); // get value

			if (variable == nullptr) // if no have this var name
			{
				NameErrorException* nameException = new NameErrorException();
				nameException->mekeException(str);
				throw nameException;
			}
		}

		else
		{
			variable = getType(str); // get type of data

			if (variable == nullptr) // if is invalid type
				throw new SyntaxException();
		}
	}

	return variable;
}

Type* Parser::getType(std::string &str)
{
	if (Helper::isInteger(str)) // if is int
	{
		int value = 0;

		if (str[0] == '-') // if is negative number
			value = (-1)*std::atoi(str.substr(1, str.size() - 1).c_str()); // get int of this string without '-'

		else // if is positive number
			value = std::atoi(str.c_str()); // get int of this string

		return new Integer(value);
	}

	else if (Helper::isBoolean(str)) // if is bool
	{
		if (str == "True")
			return new Boolean(true);

		else // if (str == "False")
			return new Boolean(false);
	}

	else if (Helper::isString(str)) // if is string
	{
		return new String(str.substr(1, str.size() - 2));
	}

	return nullptr;
}

bool Parser::isLegalVarName(const std::string& str)
{
	// if is safe word
	if (str == "True" || str == "False")
		return false;

	// if the begain is invalid
	if (str[0] != '_' && !Helper::isLetter(str[0]))
		return false;

	// if one of the str is invalid
	for (int i = 1; i < str.size(); i++)
		if (!(Helper::isDigit(str[i]) || Helper::isLetter(str[i]) || str[i] == '_'))
			return false;

	return true; // if is valid
}

bool Parser::makeAssignment(const std::string& str)
{
	int splitIndex = -1;

	// get '=' index
	for (int i = 0; i < str.size(); i++)
		if (str[i] == '=')
			splitIndex = i;

	if (splitIndex != -1) // if is valid str
	{
		Type* var = nullptr;

		// get varName and value
		std::string varName = str.substr(0, splitIndex);
		std::string stringValue = str.substr(splitIndex + 1, str.size() - splitIndex + 1);

		// remove ' ' chars
		Helper::rtrim(varName);
		Helper::trim(stringValue);
		Helper::rtrim(stringValue);

		// throw excpetion if is invalid name
		if (!isLegalVarName(varName))
		{
			NameErrorException* nameException= new NameErrorException();
			nameException->mekeException(varName);
			throw nameException;
		}

		else // if is vaid name
		{
			if (isLegalVarName(stringValue))
			{
				Type* value = getVariableValue(stringValue); // get value

				if (value == nullptr) // if no have this var name
				{
					NameErrorException* nameException = new NameErrorException();
					nameException->mekeException(stringValue);
					throw nameException;
				}
				else
				{
					if(value->isPrintable())
						var = getType(value->ToString());

					// if is invalid type
					if (var == nullptr)
						throw new SyntaxException();

					else // if is valid type
					{
						bool found = false;

						// get over the map and look for this name
						std::unordered_map<std::string, Type*>::iterator it;
						for (it = _variables.begin(); it != _variables.end(); it++)
							if (it->first == varName) // if is used name
							{
								found = true;
								delete it->second;
								it->second = var;
							}

						if (!found) // if is unused name
							_variables.insert(std::pair<std::string, Type*>(varName, var)); // insert this variable

						return true;
					}
				}
			}
			else
			{
				var = getType(stringValue); // get value type

				// if is invalid type
				if (var == nullptr)
					throw new SyntaxException();

				else // if is valid type
				{
					bool found = false;

					// get over the map and look for this name
					std::unordered_map<std::string, Type*>::iterator it;
					for (it = _variables.begin(); it != _variables.end(); it++)
						if (it->first == varName) // if is used name
						{
							found = true;
							delete it->second;
							it->second = var;
						}

					if (!found) // if is unused name
						_variables.insert(std::pair<std::string, Type*>(varName, var)); // insert this variable

					return true;
				}
			}
		}
	}

	return false;
}

Type* Parser::getVariableValue(const std::string & str)
{
	// search variavle in the map
	std::unordered_map<std::string, Type*>::iterator it;
	for (it = _variables.begin(); it != _variables.end(); it++)
		if (it->first == str) // if this var in the map
			return it->second;

	return nullptr;
}



