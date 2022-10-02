#pragma once
#include "Exceptions/OutOfRangeException.h"

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
		ListElement<T>* first;
		ListElement<T>* last;
		int size;

	public:
		List();
		List(const List<T>& other);
		List(List<T>&& other);
		~List();

		int getSize() const;
		bool isEmpty() const;

		void add(T element);

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
	List<T>::List() : first(nullptr), last(nullptr), size(0)
	{
		// Nothing to do
	}

	template<typename T>
	List<T>::List(const List<T>& other)
	{
		size = 0;
		first = last = nullptr;

		for (ListElement<T>* elem = other.first, *next = nullptr; elem != nullptr; elem = next)
		{
			add(elem->value);
			next = elem->next;
		}
	}

	template<typename T>
	List<T>::List(List<T>&& other)
	{
		size = other.size;
		first = other.first;
		last = other.last;

		for (ListElement<T>* elem = other.first, *next = nullptr; elem != nullptr; elem = next)
		{
			next = elem->next;
			elem = nullptr;
		}
	}

	template<typename T>
	List<T>::~List()
	{
		for (ListElement<T>* elem = first, *next = nullptr; elem != nullptr; elem = next)
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

		if (last == nullptr)
		{
			first = last = newlistElement;
		}
		else
		{
			last->next = newlistElement;
			newlistElement->prev = last;
			last = newlistElement;
		}
		++size;
	}

	template<typename T>
	T& List<T>::operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException(index);
		}

		ListElement<T>* elem = first;
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

		ListElement<T>* elem = first;
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
			first = last = nullptr;

			for (ListElement<T>* elem = other.first, *next = nullptr; elem != nullptr; elem = next)
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

			ListElement<T>* tmp = first;
			first = other.first;
			other.first = tmp;

			tmp = last;
			last = other.last;
			other.last = tmp;
		}
		return *this;
	}
}
