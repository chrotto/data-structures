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
