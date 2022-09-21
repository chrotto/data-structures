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
		bool isEmpty() const;

		void push(T value);

		T& first();
		T* firstOrNull();
		T& last();
		T* lastOrNull();

		bool contains(T element) const;
		
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
	bool Array<T>::isEmpty() const
	{
		return size == 0;
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
		if (isEmpty()) 
		{
			throw NoSuchElementException("The array is empty.");
		}
		return *values;
	}

	template<typename T>
	T* Array<T>::firstOrNull()
	{
		return !isEmpty() ? &first() : nullptr;
	}

	template<typename T>
	T& Array<T>::last()
	{
		if (isEmpty())
		{
			throw NoSuchElementException("The array is empty.");
		}
		return values[size - 1];
	}

	template<typename T>
	T* Array<T>::lastOrNull()
	{
		return !isEmpty() ? &last() : nullptr;
	}

	template<typename T>
	bool Array<T>::contains(T element) const
	{
		for (int i = 0; i < size; ++i)
		{
			if (values[i] == element)
			{
				return true;
			};
		}
		return false;
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
