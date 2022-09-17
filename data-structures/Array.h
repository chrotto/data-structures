#pragma once

namespace DS
{
	template<typename T>
	class Array
	{
	private:
		T* values;
		int maxSize;
		int size;

	public:
		Array();
		explicit Array(int size);
		~Array();

		const int getSize() const;

		void push(T value);

	private:
		void resize(int newSize);
	};

	template<typename T>
	Array<T>::Array() : Array(0)
	{
		// Nothing to do
	}

	template<typename T>
	Array<T>::Array(int size) : maxSize(size), size(size)
	{
		values = new T[maxSize];
	}

	template<typename T>
	Array<T>::~Array()
	{
		delete[] values;
	}

	template<typename T>
	const int Array<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	void Array<T>::push(T value)
	{
		if (size == maxSize)
		{
			resize(maxSize + 1);
		}
		values[size++] = value;
	}

	template<typename T>
	void Array<T>::resize(int newSize)
	{
		if (newSize == maxSize)
		{
			return;
		}
		maxSize = newSize;

		if (newSize < size)
		{
			size = newSize;
		}

		T* newValues = new T[newSize];
		for (int i = 0; i < size; i++)
		{
			newValues[i] = values[i];
		}

		delete[] values;
		values = newValues;
	}
}
