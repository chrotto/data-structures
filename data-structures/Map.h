#pragma once

namespace DS
{
	template<typename K, typename V>
	class MapEntry
	{
	private:
		K key;
		V value;

	public:
		MapEntry();
		MapEntry(K inKey, V inValue);

		const K& getKey() const;
		void setKey(K inKey);
		const V& getValue() const;
		void setValue(V inValue);
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

		void put(K key, V value);

		Map<K, V>& operator=(const Map<K, V>& other);
		Map<K, V>& operator=(Map<K, V>&& other);

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
	const K& MapEntry<K, V>::getKey() const
	{
		return key;
	}

	template<typename K, typename V>
	void MapEntry<K, V>::setKey(K inKey)
	{
		key = inKey;
	}

	template<typename K, typename V>
	const V& MapEntry<K, V>::getValue() const
	{
		return value;
	}

	template<typename K, typename V>
	void MapEntry<K, V>::setValue(V inValue)
	{
		value = inValue;
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
	void Map<K, V>::put(K key, V value)
	{
		int indexOfKey = indexOf(key);
		if (indexOfKey != -1)
		{
			entries[indexOfKey].setValue(value);
			return;
		}

		if (size == maxSize)
		{
			resize(maxSize + 1);
		}
		entries[size++] = MapEntry(key, value);
	}

	template<typename K, typename V>
	Map<K, V>& Map<K, V>::operator=(const Map<K, V>& other)
	{
		if (this != &other)
		{
			maxSize = other.maxSize;
			size = other.size;
			delete[] entries;
			entries = new MapEntry[maxSize];

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
			if (entries[i].getKey() == key)
			{
				return i;
			}
		}
		return -1;
	}
}
