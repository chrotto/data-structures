#include "pch.h"
#include "Map.h"
#include <string>

TEST(Map, InitializeWithSizeZero)
{
	DS::Map<std::string, int> map = DS::Map<std::string, int>();

	EXPECT_EQ(map.getSize(), 0);
}
