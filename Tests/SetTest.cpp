#include "pch.h"
#include "Set.h"

TEST(Set, InitializeWithSizeZero)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_EQ(set.getSize(), 0);
}

TEST(Set, AddElement)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_EQ(set.getSize(), 0);
	set.add(1);
	EXPECT_EQ(set.getSize(), 1);
	set.add(2);
	EXPECT_EQ(set.getSize(), 2);
}

TEST(Set, DoNotAddDuplicates)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_EQ(set.getSize(), 0);
	set.add(1);
	EXPECT_EQ(set.getSize(), 1);
	set.add(2);
	EXPECT_EQ(set.getSize(), 2);
	set.add(2);
	EXPECT_EQ(set.getSize(), 2);
}

TEST(Set, ContainsElement)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);
	set.add(20);
	set.add(30);

	EXPECT_TRUE(set.contains(10));
	EXPECT_TRUE(set.contains(20));
	EXPECT_TRUE(set.contains(30));
	EXPECT_FALSE(set.contains(40));
}

TEST(Set, ContainsElementInEmptySet)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_FALSE(set.contains(10));
}

TEST(Set, EmptyCheckOnEmptySet)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_TRUE(set.isEmpty());
}

TEST(Set, EmptyCheckOnNonEmptySet)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);

	EXPECT_FALSE(set.isEmpty());
}