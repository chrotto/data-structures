#pragma once

namespace DS
{
	template<typename T>
	class Array
	{
	private:
		int size;

	public:
		Array();
		explicit Array(int size);

		const int getSize() const;
	};

	template<typename T>
	Array<T>::Array() : Array(10)
	{
		// Nothing to do
	}
	
	template<typename T>
	Array<T>::Array(int size) : size(size)
	{
		// Nothing to do
	}

	template<typename T>
	const int Array<T>::getSize() const
	{
		return size;
	}
}
