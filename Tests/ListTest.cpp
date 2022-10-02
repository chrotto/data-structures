#include "pch.h"
#include "List.h"

TEST(List, InitializeEmptyList)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_EQ(list.getSize(), 0);
}