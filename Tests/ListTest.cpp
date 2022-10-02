#include "pch.h"
#include "List.h"

TEST(List, InitializeEmptyList)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_EQ(list.getSize(), 0);
}

TEST(List, AddElementToList)
{
	DS::List<int> list = DS::List<int>();
	
	list.add(1);
	EXPECT_EQ(list.getSize(), 1);
	list.add(2);
	EXPECT_EQ(list.getSize(), 2);
	list.add(3);
	EXPECT_EQ(list.getSize(), 3);
}

TEST(List, EmptyCheckOnEmptyList)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_TRUE(list.isEmpty());
}

TEST(List, EmptyCheckOnNonEmptyList)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);

	EXPECT_FALSE(list.isEmpty());
}