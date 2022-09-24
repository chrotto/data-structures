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

TEST(Set, FirstElementAccess)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);
	set.add(20);

	EXPECT_EQ(set.first(), 10);
}

TEST(Set, FirstElementAccessWithNoSuchElementException)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_THROW(set.first(), DS::NoSuchElementException);
}

TEST(Set, FirstOrNullElementAccessOfExistingElement)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);
	set.add(20);

	EXPECT_EQ(*set.firstOrNull(), 10);
}

TEST(Set, FirstOrNullElementAccessOfEmptySet)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_EQ(set.firstOrNull(), nullptr);
}

TEST(Set, LastElementAccess)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);
	set.add(20);

	EXPECT_EQ(set.last(), 20);
}

TEST(Set, LastElementAccessWithNoSuchElementException)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_THROW(set.last(), DS::NoSuchElementException);
}

TEST(Set, LastOrNullElementAccessOfExistingElement)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);
	set.add(20);
	set.add(10);

	EXPECT_EQ(*set.lastOrNull(), 20);
}

TEST(Set, LastOrNullElementAccessOfEmptySet)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_EQ(set.lastOrNull(), nullptr);
}

TEST(Set, IndexOperatorAccess)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);
	set.add(20);
	set.add(30);

	EXPECT_EQ(set[0], 10);
	EXPECT_EQ(set[1], 20);
	EXPECT_EQ(set[2], 30);
}

TEST(Set, IndexOperatorAccessOutOfRange)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(10);

	EXPECT_THROW(set[1], DS::OutOfRangeException);
	EXPECT_THROW(set[-1], DS::OutOfRangeException);
}

TEST(Set, ContainsOneElementFulfillingThePredicate)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(1);
	set.add(2);
	set.add(3);
	set.add(4);

	auto predicate = [](const int& x) { return x % 2 == 0; };
	EXPECT_TRUE(set.any(predicate));
}

TEST(Set, ContainsNoElementFulfillingThePredicate)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(1);
	set.add(2);
	set.add(3);
	set.add(4);

	auto predicate = [](const int& x) { return x == 0; };
	EXPECT_FALSE(set.any(predicate));
}

TEST(Set, ContainsOneElementFulfillingThePredicateInEmptySet)
{
	DS::Set<int> set = DS::Set<int>();

	auto predicate = [](const int& x) { return x == 0; };
	EXPECT_FALSE(set.any(predicate));
}

TEST(Set, FindElementInEmptySet)
{
	DS::Set<int> set = DS::Set<int>();
	auto predicate = [](const int& x) { return x % 2 == 0; };

	EXPECT_EQ(set.find(predicate), nullptr);
}

TEST(Set, FindElementInSet)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(1);
	set.add(2);
	set.add(3);
	auto predicate = [](const int& x) { return x % 2 == 0; };

	EXPECT_EQ(*set.find(predicate), 2);
}

TEST(Set, FilterSetByEvenNumbers)
{
	DS::Set<int> set = DS::Set<int>();
	set.add(1);
	set.add(2);
	set.add(5);
	set.add(6);

	DS::Set<int> filteredSet = set.filter([](const int& x) { return x % 2 == 0; });
	EXPECT_EQ(filteredSet.getSize(), 2);
	EXPECT_EQ(filteredSet[0], 2);
	EXPECT_EQ(filteredSet[1], 6);
}

TEST(Set, FilterSetEmptySet)
{
	DS::Set<int> set = DS::Set<int>();

	DS::Set<int> filteredSet = set.filter([](const int& x) { return x % 2 == 0; });
	EXPECT_EQ(filteredSet.getSize(), 0);
}
