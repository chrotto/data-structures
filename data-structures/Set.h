#pragma once

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
}
