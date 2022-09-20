#pragma once
#include <exception>
#include <string>

namespace DS
{
	class NoSuchElementException : public std::exception
	{
	public:
		NoSuchElementException(std::string errorMessage);
	};
}