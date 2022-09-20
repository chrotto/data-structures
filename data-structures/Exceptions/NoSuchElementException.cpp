#include "NoSuchElementException.h"

DS::NoSuchElementException::NoSuchElementException(std::string errorMessage) : std::exception(errorMessage.c_str())
{
	// Nothing to do
}
