#pragma once
#include "Exceptions/OutOfRangeException.h"
#include "Exceptions/NoSuchElementException.h"

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

		constexpr int getSize() const;

		void push(T value);

		T& first();
		
		T& operator[](int index);
		constexpr T& operator[](int index) const;

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
	constexpr int Array<T>::getSize() const
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
	T& Array<T>::first()
	{
		if (size <= 0) 
		{
			throw NoSuchElementException("The array is empty.");
		}
		return *values;
	}

	template<typename T>
	T& Array<T>::operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException(index);
		}
		return values[index];
	}

	template<typename T>
	constexpr T& Array<T>::operator[](int index) const
	{
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException(index);
		}
		return values[index];
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
