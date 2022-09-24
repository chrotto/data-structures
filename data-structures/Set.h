#pragma once
#include <functional>
#include "Exceptions/NoSuchElementException.h"
#include "Exceptions/OutOfRangeException.h"

namespace DS
{
	template<typename T>
	class Set
	{
	private:
		T* values;
		int maxSize;
		int size;

	public:
		Set();
		Set(const Set<T>& other);
		Set(Set<T>&& other);
		~Set();

		Set<T>& operator=(const Set<T>& other);
		Set<T>& operator=(Set<T>&& other);

		constexpr int getSize() const;
		bool isEmpty() const;
		bool contains(T element) const;
		bool any(std::function<bool(const T&)> predicate);

		void add(T element);

		T& first();
		T* firstOrNull();
		T& last();
		T* lastOrNull();

		T* find(std::function<bool(const T&)> predicate);

		Set<T> filter(std::function<bool(const T&)> predicate);

		T& operator[](int index);
		constexpr T& operator[](int index) const;

	private:
		void resize(int newSize);
	};

	template<typename T>
	Set<T>::Set() : maxSize(1), size(0)
	{
		values = new T[maxSize];
	}

	template<typename T>
	Set<T>::Set(const Set<T>& other)
	{
		size = other.size;
		maxSize = other.maxSize;
		values = new T[maxSize];

		for (int i = 0; i < size; ++i)
		{
			values[i] = other.values[i];
		}
	}

	template<typename T>
	Set<T>::Set(Set<T>&& other)
	{
		size = other.size;
		maxSize = other.maxSize;
		values = other.values;

		other.values = nullptr;
	}

	template<typename T>
	Set<T>::~Set()
	{
		delete[] values;
	}

	template<typename T>
	Set<T>& Set<T>::operator=(const Set<T>& other)
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
	Set<T>& Set<T>::operator=(Set<T>&& other)
	{
		if (this != &other)
		{
			maxSize = other.maxSize;
			size = other.size;
			values = other.values;

			T* tmp = values;
			values = other.values;
			other.values = tmp;
		}
		return *this;
	}
	
	template<typename T>
	constexpr int Set<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	bool Set<T>::isEmpty() const
	{
		return size == 0;
	}

	template<typename T>
	bool Set<T>::contains(T element) const
	{
		for (int i = 0; i < size; i++)
		{
			if (values[i] == element)
			{
				return true;
			}
		}
		return false;
	}

	template<typename T>
	bool Set<T>::any(std::function<bool(const T&)> predicate)
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
	void Set<T>::add(T element)
	{
		if (contains(element))
		{
			return;
		}

		if (size == maxSize)
		{
			resize(maxSize + 1);
		}
		values[size++] = element;
	}

	template<typename T>
	T& Set<T>::first()
	{
		if (isEmpty())
		{
			throw NoSuchElementException("The set is empty.");
		}
		return *values;
	}

	template<typename T>
	T* Set<T>::firstOrNull()
	{
		return !isEmpty() ? &first() : nullptr;
	}

	template<typename T>
	T& Set<T>::last()
	{
		if (isEmpty())
		{
			throw NoSuchElementException("The set is empty.");
		}
		return values[size - 1];
	}

	template<typename T>
	T* Set<T>::lastOrNull()
	{
		return !isEmpty() ? &last() : nullptr;
	}

	template<typename T>
	T* Set<T>::find(std::function<bool(const T&)> predicate)
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
	Set<T> Set<T>::filter(std::function<bool(const T&)> predicate)
	{
		Set<T> filteredSet = Set<T>();
		for (int i = 0; i < size; ++i)
		{
			if (predicate(values[i]))
			{
				filteredSet.add(values[i]);
			}
		}
		return filteredSet;
	}

	template<typename T>
	T& Set<T>::operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException(index);
		}
		return values[index];
	}

	template<typename T>
	constexpr T& Set<T>::operator[](int index) const
	{
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException(index);
		}
		return values[index];
	}

	template<typename T>
	void Set<T>::resize(int newSize)
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
