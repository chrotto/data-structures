#pragma once
#include <functional>
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
		Array(const Array<T>& other);
		Array(Array<T>&& other);
		~Array();

		constexpr int getSize() const;
		bool isEmpty() const;

		void push(T value);

		T& first();
		T* firstOrNull();
		T& last();
		T* lastOrNull();

		bool contains(T element) const;

		Array<T> filter(std::function<bool(T&)> predicate);

		Array<T>& operator=(const Array<T>& other);
		Array<T>& operator=(Array<T>&& other);

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
	Array<T>::Array(const Array<T>& other)
	{
		maxSize = other.maxSize;
		size = other.size;
		values = new T[maxSize];

		for (int i = 0; i < size; ++i)
		{
			values[i] = other.values[i];
		}
	}

	template<typename T>
	Array<T>::Array(Array<T>&& other)
	{
		maxSize = other.maxSize;
		size = other.size;
		values = other.values;

		other.values = nullptr;
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
	Array<T> Array<T>::filter(std::function<bool(T&)> predicate)
	{
		Array<T> filteredArray = Array<T>();
		for (int i = 0; i < size; ++i)
		{
			if (predicate(values[i]))
			{
				filteredArray.push(values[i]);
			}
		}
		return filteredArray;
	}

	template<typename T>
	Array<T>& Array<T>::operator=(const Array<T>& other)
	{
		if (this != &other)
		{
			maxSize = other.maxSize;
			size = other.size;
			delete[] values;
			values = new T[maxSize];

			for (int i = 0; i < size; ++i)
			{
				values[i] = other.values[i];
			}
		}
		return *this;
	}

	template<typename T>
	Array<T>& Array<T>::operator=(Array<T>&& other)
	{
		if (this != &other)
		{
			maxSize = other.maxSize;
			size = other.size;

			T* tmp = values;
			values = other.values;
			other.values = tmp;
		}
		return *this;
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
