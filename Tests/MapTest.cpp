#include "pch.h"
#include "Map.h"
#include <string>

TEST(Map, InitializeWithSizeZero)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();

	EXPECT_EQ(map.getSize(), 0);
}

TEST(Map, AddEntry)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();

	EXPECT_EQ(map.getSize(), 0);
	map.put("a", 1);
	EXPECT_EQ(map.getSize(), 1);
	map.put("b", 1);
	EXPECT_EQ(map.getSize(), 2);
}

TEST(Map, DoNotAddDuplicateKeys)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();

	EXPECT_EQ(map.getSize(), 0);
	map.put("a", 1);
	EXPECT_EQ(map.getSize(), 1);
	map.put("b", 1);
	EXPECT_EQ(map.getSize(), 2);
	map.put("a", 1);
	EXPECT_EQ(map.getSize(), 2);
	map.put("a", 2);
	EXPECT_EQ(map.getSize(), 2);
}

TEST(Map, EmptyCheckOnEmptyMap)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();

	EXPECT_TRUE(map.isEmpty());
}

TEST(Map, EmptyCheckOnNonEmptyMap)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();
	map.put("a", 1);

	EXPECT_FALSE(map.isEmpty());
}

TEST(Map, ContainsKey)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();

	EXPECT_FALSE(map.containsKey("a"));
}

TEST(Map, ContainsKeyInEmptyMap)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();
	map.put("a", 1);

	EXPECT_TRUE(map.containsKey("a"));
}

TEST(Map, IndexOperatorAccess)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();
	map.put("a", 1);
	map.put("b", 2);
	map.put("c", 3);

	EXPECT_EQ(*map["a"], 1);
	EXPECT_EQ(*map["b"], 2);
	EXPECT_EQ(*map["c"], 3);
}

TEST(Map, IndexOperatorAccessForNotExistingKey)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();
	map.put("a", 1);

	EXPECT_EQ(map["b"], nullptr);
}
