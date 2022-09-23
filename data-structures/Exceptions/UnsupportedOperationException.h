#pragma once
#include <exception>
#include <string>

namespace DS
{
	class UnsupportedOperationException : public std::exception
	{
	public:
		UnsupportedOperationException();
	};
}
