#include "OutOfRangeException.h"
#include <format>

DS::OutOfRangeException::OutOfRangeException(int index) : index(index)
{
    message = std::format("The index {0} is out of range.", index);
    
}

const char* DS::OutOfRangeException::what() const
{
    return message.c_str();
}