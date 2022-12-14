#pragma once
#include <functional>

namespace DS
{
	template<typename K, typename V>
	class MapEntry
	{
	public:
		K key;
		V value;

		MapEntry();
		MapEntry(K inKey, V inValue);
	};


	template<typename K, typename V>
	class Map
	{
	private:
		int maxSize;
		int size;
		MapEntry<K, V>* entries;

	public:
		Map();
		Map(const Map<K, V>& other);
		Map(Map<K, V>&& other);
		~Map();

		int getSize() const;
		bool isEmpty() const;

		void put(K key, V value);

		bool containsKey(K key) const;
		bool any(std::function<bool(const MapEntry<K, V>&)> predicate);

		Map<K, V> filter(std::function<bool(const MapEntry<K, V>&)> predicate);
		template<typename R>
		Map<R, V> mapKeys(std::function<R(const MapEntry<K, V>&)> transform);
		template<typename R>
		Map<K, R> mapValues(std::function<R(const MapEntry<K, V>&)> transform);

		Map<K, V>& operator=(const Map<K, V>& other);
		Map<K, V>& operator=(Map<K, V>&& other);

		V* operator[](K key);
		constexpr V* operator[](K key) const;

	private:
		void resize(int newSize);
		int indexOf(K key);
	};


	template<typename K, typename V>
	MapEntry<K, V>::MapEntry()
	{
		// Nothing to do
	}

	template<typename K, typename V>
	MapEntry<K, V>::MapEntry(K inKey, V inValue) : key(inKey), value(inValue)
	{
		// Nothing to do
	}

	template<typename K, typename V>
	Map<K, V>::Map() : maxSize(1), size(0)
	{
		entries = new MapEntry<K, V>[maxSize];
	}

	template<typename K, typename V>
	Map<K, V>::Map(const Map<K, V>& other)
	{
		maxSize = other.maxSize;
		size = other.size;
		entries = new MapEntry<K, V>[maxSize];

		for (int i = 0; i < size; ++i)
		{
			entries[i] = other.entries[i];
		}
	}

	template<typename K, typename V>
	Map<K, V>::Map(Map<K, V>&& other)
	{
		maxSize = other.maxSize;
		size = other.size;
		entries = other.entries;
		
		other.entries = nullptr;
	}

	template<typename K, typename V>
	Map<K, V>::~Map()
	{
		delete[] entries;
	}

	template<typename K, typename V>
	int Map<K, V>::getSize() const
	{
		return size;
	}

	template<typename K, typename V>
	bool Map<K, V>::isEmpty() const
	{
		return size == 0;
	}

	template<typename K, typename V>
	void Map<K, V>::put(K key, V value)
	{
		int indexOfKey = indexOf(key);
		if (indexOfKey != -1)
		{
			entries[indexOfKey].value = value;
			return;
		}

		if (size == maxSize)
		{
			resize(maxSize + 1);
		}
		entries[size++] = MapEntry(key, value);
	}

	template<typename K, typename V>
	bool Map<K, V>::containsKey(K key) const
	{
		for (int i = 0; i < size; ++i)
		{
			if (entries[i].key == key)
			{
				return true;
			}
		}
		return false;
	}

	template<typename K, typename V>
	bool Map<K, V>::any(std::function<bool(const MapEntry<K, V>&)> predicate)
	{
		for (int i = 0; i < size; ++i)
		{
			if (predicate(entries[i]))
			{
				return true;
			}
		}
		return false;
	}

	template<typename K, typename V>
	Map<K, V> Map<K, V>::filter(std::function<bool(const MapEntry<K, V>&)> predicate)
	{
		Map<K, V> filteredMap = Map<K, V>();
		for (int i = 0; i < size; ++i)
		{
			if (predicate(entries[i]))
			{
				filteredMap.put(entries[i].key, entries[i].value);
			}
		}
		return filteredMap;
	}

	template<typename K, typename V>
	template<typename R>
	Map<R, V> Map<K, V>::mapKeys(std::function<R(const MapEntry<K, V>&)> transform)
	{
		Map<R, V> mappedMap = Map<R, V>();
		for (int i = 0; i < size; ++i)
		{
			mappedMap.put(transform(entries[i]), entries[i].value);
		}
		return mappedMap;
	}

	template<typename K, typename V>
	template<typename R>
	Map<K, R> Map<K, V>::mapValues(std::function<R(const MapEntry<K, V>&)> transform)
	{
		Map<K, R> mappedMap = Map<K, R>();
		for (int i = 0; i < size; ++i)
		{
			mappedMap.put(entries[i].key, transform(entries[i]));
		}
		return mappedMap;
	}

	template<typename K, typename V>
	Map<K, V>& Map<K, V>::operator=(const Map<K, V>& other)
	{
		if (this != &other)
		{
			maxSize = other.maxSize;
			size = other.size;
			delete[] entries;
			entries = new MapEntry<K, V>[maxSize];

			for (int i = 0; i < size; ++i)
			{
				entries[i] = other.entries[i];
			}
		}
		return *this;
	}

	template<typename K, typename V>
	Map<K, V>& Map<K, V>::operator=(Map<K, V>&& other)
	{
		if (this != &other)
		{
			maxSize = other.maxSize;
			size = other.size;

			MapEntry<K, V>* tmp = new MapEntry<K, V>[maxSize];
			entries = other.entries;
			other.entries = tmp;
		}
		return *this;
	}

	template<typename K, typename V>
	V* Map<K, V>::operator[](K key)
	{
		int indexOfKey = indexOf(key);
		return indexOfKey == -1 ? nullptr : &entries[indexOfKey].value;
	}

	template<typename K, typename V>
	constexpr V* Map<K, V>::operator[](K key) const
	{
		int indexOfKey = indexOf(key);
		return indexOfKey == -1 ? nullptr : &entries[indexOfKey].value;
	}

	template<typename K, typename V>
	void Map<K, V>::resize(int newSize)
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

		MapEntry<K, V>* newEntries = new MapEntry<K, V>[newSize];
		for (int i = 0; i < size; i++)
		{
			newEntries[i] = entries[i];
		}

		delete[] entries;
		entries = newEntries;
	}

	template<typename K, typename V>
	int Map<K, V>::indexOf(K key)
	{
		for (int i = 0; i < size; ++i)
		{
			if (entries[i].key == key)
			{
				return i;
			}
		}
		return -1;
	}
}
