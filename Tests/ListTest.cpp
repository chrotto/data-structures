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

TEST(List, IndexOperatorAccess)
{
	DS::List<int> list = DS::List<int>();
	list.add(10);
	list.add(20);
	list.add(30);

	EXPECT_EQ(list[0], 10);
	EXPECT_EQ(list[1], 20);
	EXPECT_EQ(list[2], 30);
}

TEST(List, IndexOperatorAccessOutOfRange)
{
	DS::List<int> list = DS::List<int>();
	list.add(10);

	EXPECT_THROW(list[1], DS::OutOfRangeException);
	EXPECT_THROW(list[-1], DS::OutOfRangeException);
}