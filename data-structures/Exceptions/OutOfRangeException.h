#pragma once
#include <stdexcept>
#include <string>

namespace DS
{
	class OutOfRangeException : public std::exception
	{
	private:
		int index;
		std::string message;
		
	public:
		OutOfRangeException(int index);

		virtual const char* what() const override;
	};
}
