#include "type.h"
#include "InterperterException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"
#include "parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Yonatan Gabay"


int main(int argc, char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);

	while (input_string != "quit()")
	{
		try
		{
			// prasing command
			Type* variable = Parser::parseString(input_string);

			// print the variable if is printable
			if (variable != nullptr)
			{
				if (variable->isPrintable())
					std::cout << variable->ToString() << std::endl;

				// delete it if is temp
				if (variable->getIsTemp())
					delete variable;
			}
		}
		catch(InterperterException* e)
		{
			std::cout << e->what() << std::endl;
			delete e;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}


