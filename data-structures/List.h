#pragma once
#include <functional>
#include "Exceptions/OutOfRangeException.h"
#include "Exceptions/NoSuchElementException.h"

namespace DS
{
	template<typename T>
	class List;

	template<typename T>
	class ListElement
	{
	private:
		ListElement* prev;
		ListElement* next;
		T value;

	public:
		ListElement(T value, ListElement* prev = nullptr, ListElement* next = nullptr);

		friend class List<T>;
	};

	template<typename T>
	class List
	{
	private:
		ListElement<T>* firstElement;
		ListElement<T>* lastElement;
		int size;

	public:
		List();
		List(const List<T>& other);
		List(List<T>&& other);
		~List();

		int getSize() const;
		bool isEmpty() const;

		void add(T element);

		T& first();
		T* firstOrNull();
		T& last();
		T* lastOrNull();

		T* find(std::function<bool(const T&)> predicate);

		T& operator[](int index);
		constexpr T& operator[](int index) const;

		List<T>& operator=(const List<T>& other);
		List<T>& operator=(List<T>&& other);
	};

	template<typename T>
	ListElement<T>::ListElement(T inValue, ListElement* inPrev, ListElement* inNext) : value(inValue), prev(inPrev), next(inNext)
	{
		// Nothing to do
	}
	
	template<typename T>
	List<T>::List() : firstElement(nullptr), lastElement(nullptr), size(0)
	{
		// Nothing to do
	}

	template<typename T>
	List<T>::List(const List<T>& other)
	{
		size = 0;
		firstElement = lastElement = nullptr;

		for (ListElement<T>* elem = other.firstElement, *next = nullptr; elem != nullptr; elem = next)
		{
			add(elem->value);
			next = elem->next;
		}
	}

	template<typename T>
	List<T>::List(List<T>&& other)
	{
		size = other.size;
		firstElement = other.firstElement;
		lastElement = other.lastElement;

		for (ListElement<T>* elem = other.firstElement, *next = nullptr; elem != nullptr; elem = next)
		{
			next = elem->next;
			elem = nullptr;
		}
	}

	template<typename T>
	List<T>::~List()
	{
		for (ListElement<T>* elem = firstElement, *next = nullptr; elem != nullptr; elem = next)
		{
			next = elem->next;
			delete elem;
		}
	}

	template<typename T>
	int List<T>::getSize() const
	{
		return size;
	}

	template<typename T>
	bool List<T>::isEmpty() const
	{
		return size == 0;
	}

	template<typename T>
	void List<T>::add(T element)
	{
		ListElement<T>* newlistElement = new ListElement<T>(element);

		if (lastElement == nullptr)
		{
			firstElement = lastElement = newlistElement;
		}
		else
		{
			lastElement->next = newlistElement;
			newlistElement->prev = lastElement;
			lastElement = newlistElement;
		}
		++size;
	}

	template<typename T>
	T& List<T>::first()
	{
		if (isEmpty())
		{
			throw NoSuchElementException("The list is empty.");
		}
		return firstElement->value;
	}

	template<typename T>
	T* List<T>::firstOrNull()
	{
		return isEmpty() ? nullptr : &(*firstElement).value;
	}

	template<typename T>
	T& List<T>::last()
	{
		if (isEmpty())
		{
			throw NoSuchElementException("The list is empty.");
		}
		return lastElement->value;
	}

	template<typename T>
	T* List<T>::lastOrNull()
	{
		return isEmpty() ? nullptr : &(*lastElement).value;
	}

	template<typename T>
	T* List<T>::find(std::function<bool(const T&)> predicate)
	{
		for (ListElement<T>* elem = firstElement; elem != lastElement; elem = elem->next)
		{
			if (predicate(elem->value))
			{
				return &(*elem).value;
			}
		}
		return nullptr;
	}

	template<typename T>
	T& List<T>::operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException(index);
		}

		ListElement<T>* elem = firstElement;
		for (int i = 1; i <= index; ++i)
		{
			elem = elem->next;
		}
		return elem->value;
	}

	template<typename T>
	constexpr T& List<T>::operator[](int index) const
	{
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException(index);
		}

		ListElement<T>* elem = firstElement;
		for (int i = 0; i <= index; ++i)
		{
			elem = elem->next;
		}
		return elem->value;
	}

	template<typename T>
	List<T>& List<T>::operator=(const List<T>& other)
	{
		if (this != &other)
		{
			size = 0;
			firstElement = lastElement = nullptr;

			for (ListElement<T>* elem = other.firstElement, *next = nullptr; elem != nullptr; elem = next)
			{
				add(elem->value);
				next = elem->next;
			}
		}
		return *this;
	}

	template<typename T>
	List<T>& List<T>::operator=(List<T>&& other)
	{
		if (this != &other)
		{
			size = other.size;

			ListElement<T>* tmp = firstElement;
			firstElement = other.firstElement;
			other.firstElement = tmp;

			tmp = lastElement;
			lastElement = other.lastElement;
			other.lastElement = tmp;
		}
		return *this;
	}
}
