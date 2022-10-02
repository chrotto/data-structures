#pragma once

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
		~List();

		int getSize() const;

		void add(T element);
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
}
