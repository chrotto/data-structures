#pragma once
#include <functional>
#include <algorithm>
#include "Exceptions/OutOfRangeException.h"
#include "Exceptions/NoSuchElementException.h"
#include "Exceptions/UnsupportedOperationException.h"

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

		T* find(std::function<bool(const T&)> predicate);

		bool contains(T element) const;
		bool any(std::function<bool(const T&)> predicate);

		Array<T> filter(std::function<bool(T&)> predicate);
		template<typename R>
		Array<R> map(std::function<R(T)> transform);
		T reduce(std::function<T(T, T&)> operation);
		template<typename S>
		S fold(std::function<S(S, T&)> operation, S initialValue);

		Array<T> sort(std::function<bool(T& x, T& b)> comparison);

		Array<T>& operator=(const Array<T>& other);
		Array<T>& operator=(Array<T>&& other);

		T& operator[](int index);
		constexpr T& operator[](int index) const;

		Array<T> operator+(const Array<T>& rhs);
		Array<T>& operator+=(const Array<T>& rhs);

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
	T* Array<T>::find(std::function<bool(const T&)> predicate)
	{
		for (int i = 0; i < size; ++i)
		{
			if (predicate(values[i]))
			{
				return &values[i];
			}
		}
		return nullptr;
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
	bool Array<T>::any(std::function<bool(const T&)> predicate)
	{
		for (int i = 0; i < size; ++i)
		{
			if (predicate(values[i]))
			{
				return true;
			}
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
	Array<T> Array<T>::sort(std::function<bool(T& x, T& b)> comparison)
	{
		Array<T> sortedArray(*this);
		std::sort(sortedArray.values, sortedArray.values + size, comparison);
		return sortedArray;
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
	Array<T> Array<T>::operator+(const Array<T>& rhs)
	{
		return Array<T>(*this) += rhs;
	}

	template<typename T>
	Array<T>& Array<T>::operator+=(const Array<T>& rhs)
	{
		int oldSize = size;
		int newSize = size + rhs.size;
		resize(newSize);

		for (int i = 0; i < rhs.size; i++)
		{
			push(rhs.values[i]);
		}
		return *this;
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

	template<typename T>
	template<typename R>
	Array<R> Array<T>::map(std::function<R(T)> transform)
	{
		Array<R> mappedArray = Array<R>(size);
		for (int i = 0; i < size; ++i)
		{
			mappedArray[i] = transform(values[i]);
		}
		return mappedArray;
	}

	template<typename T>
	T Array<T>::reduce(std::function<T(T, T&)> operation)
	{
		if (isEmpty())
		{
			throw UnsupportedOperationException();
		}

		T acc = first();
		for (int i = 1; i < size; ++i)
		{
			acc = operation(acc, values[i]);
		}
		return acc;
	}

	template<typename T>
	template<typename S>
	S Array<T>::fold(std::function<S(S, T&)> operation, S initialValue)
	{
		if (isEmpty())
		{
			return initialValue;
		}

		S acc = initialValue;
		for (int i = 0; i < size; ++i)
		{
			acc = operation(acc, values[i]);
		}
		return acc;
	}
}
