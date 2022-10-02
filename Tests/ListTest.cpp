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

TEST(List, FirstElementAccess)
{
	DS::List<int> list = DS::List<int>();
	list.add(10);
	list.add(20);

	EXPECT_EQ(list.first(), 10);
}

TEST(List, FirstElementAccessWithNoSuchElementException)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_THROW(list.first(), DS::NoSuchElementException);
}

TEST(List, FirstOrNullElementAccessOfExistingElement)
{
	DS::List<int> list = DS::List<int>();
	list.add(10);
	list.add(20);

	EXPECT_EQ(*list.firstOrNull(), 10);
}

TEST(List, FirstOrNullElementAccessOfEmptyList)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_EQ(list.firstOrNull(), nullptr);
}

TEST(List, LastElementAccess)
{
	DS::List<int> list = DS::List<int>();
	list.add(10);
	list.add(20);

	EXPECT_EQ(list.last(), 20);
}

TEST(List, LastElementAccessWithNoSuchElementException)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_THROW(list.last(), DS::NoSuchElementException);
}

TEST(List, LastOrNullElementAccessOfExistingElement)
{
	DS::List<int> list = DS::List<int>();
	list.add(10);
	list.add(20);

	EXPECT_EQ(*list.lastOrNull(), 20);
}

TEST(List, LastOrNullElementAccessOfEmptyList)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_EQ(list.lastOrNull(), nullptr);
}

TEST(List, FindElementInEmptyList)
{
	DS::List<int> list = DS::List<int>();
	auto predicate = [](const int& x) { return x % 2 == 0; };

	EXPECT_EQ(list.find(predicate), nullptr);
}

TEST(List, FindElementInList)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	list.add(3);
	auto predicate = [](const int& x) { return x % 2 == 0; };

	EXPECT_EQ(*list.find(predicate), 2);
}

TEST(List, ContainsElement)
{
	DS::List<int> list = DS::List<int>();
	list.add(10);
	list.add(20);
	list.add(30);

	EXPECT_TRUE(list.contains(10));
	EXPECT_TRUE(list.contains(20));
	EXPECT_TRUE(list.contains(30));
	EXPECT_FALSE(list.contains(40));
}

TEST(List, ContainsElementInEmptyArry)
{
	DS::List<int> list = DS::List<int>();

	EXPECT_FALSE(list.contains(10));
}
