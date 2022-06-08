#include "InterperterException.h"

InterperterException::InterperterException(std::string message) : std::exception(message.c_str()) {}
