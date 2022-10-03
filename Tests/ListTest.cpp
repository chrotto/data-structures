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

TEST(List, ContainsOneElementFulfillingThePredicate)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);

	auto predicate = [](const int& x) { return x % 2 == 0; };
	EXPECT_TRUE(list.any(predicate));
}

TEST(List, ContainsNoElementFulfillingThePredicate)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);

	auto predicate = [](const int& x) { return x == 0; };
	EXPECT_FALSE(list.any(predicate));
}

TEST(List, ContainsNoElementFulfillingThePredicateInEmptyList)
{
	DS::List<int> list = DS::List<int>();

	auto predicate = [](const int& x) { return x == 0; };
	EXPECT_FALSE(list.any(predicate));
}

TEST(List, FilterListByEvenNumbers)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	list.add(5);
	list.add(6);
	list.add(6);

	DS::List<int> filteredList = list.filter([](const int& x) { return x % 2 == 0; });
	EXPECT_EQ(filteredList.getSize(), 3);
	EXPECT_EQ(filteredList[0], 2);
	EXPECT_EQ(filteredList[1], 6);
	EXPECT_EQ(filteredList[2], 6);
}

TEST(List, FilterListEmptyList)
{
	DS::List<int> list = DS::List<int>();

	DS::List<int> filteredList = list.filter([](const int& x) { return x % 2 == 0; });
	EXPECT_EQ(filteredList.getSize(), 0);
}

TEST(List, MapListOfEvenNumbersToOddNumbers)
{
	DS::List<int> list = DS::List<int>();
	list.add(2);
	list.add(4);
	list.add(6);
	list.add(8);

	auto transform = [](int x) {return x + 1; };
	DS::List<int> mappedList = list.map<int>(transform);

	EXPECT_EQ(list[0], 2);
	EXPECT_EQ(list[1], 4);
	EXPECT_EQ(list[2], 6);
	EXPECT_EQ(list[3], 8);

	EXPECT_EQ(mappedList[0], 3);
	EXPECT_EQ(mappedList[1], 5);
	EXPECT_EQ(mappedList[2], 7);
	EXPECT_EQ(mappedList[3], 9);
}

TEST(List, MapListOfIntsToStrings)
{
	DS::List<int> list = DS::List<int>();
	list.add(2);
	list.add(4);
	list.add(6);
	list.add(8);

	auto transform = [](int x) {return std::to_string(x); };
	DS::List<std::string> mappedList = list.map<std::string>(transform);

	EXPECT_EQ(list[0], 2);
	EXPECT_EQ(list[1], 4);
	EXPECT_EQ(list[2], 6);
	EXPECT_EQ(list[3], 8);

	EXPECT_EQ(mappedList[0], "2");
	EXPECT_EQ(mappedList[1], "4");
	EXPECT_EQ(mappedList[2], "6");
	EXPECT_EQ(mappedList[3], "8");
}

TEST(List, MapOfEmptyList)
{
	DS::List<int> list = DS::List<int>();

	auto transform = [](int x) {return x + 1; };
	DS::List<int> mappedList = list.map<int>(transform);

	EXPECT_TRUE(mappedList.isEmpty());
}

TEST(List, ReduceEmptyList)
{
	DS::List<int> list = DS::List<int>();
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_THROW(list.reduce(operation), DS::UnsupportedOperationException);
}

TEST(List, ReduceListWithOneElement)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(list.reduce(operation), 1);
}

TEST(List, ReduceListWithMultipleElements)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	list.add(3);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(list.reduce(operation), 6);
}

TEST(List, FoldEmptyList)
{
	DS::List<int> list = DS::List<int>();
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(list.fold<int>(operation, 0), 0);
}

TEST(List, FoldListWithOneElement)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(list.fold<int>(operation, 4), 5);
}

TEST(List, FoldListWithMultipleElements)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	list.add(3);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(list.fold<int>(operation, 4), 10);
}

TEST(List, CopyAssignmentOperator)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	DS::List<int> list2 = DS::List<int>();
	list2 = list;

	EXPECT_EQ(list.getSize(), 2);
	EXPECT_EQ(list[0], 1);
	EXPECT_EQ(list[1], 2);
	EXPECT_EQ(list2.getSize(), 2);
	EXPECT_EQ(list2[0], 1);
	EXPECT_EQ(list2[1], 2);
}

TEST(List, MoveAssignmentOperator)
{
	DS::List<int> list = DS::List<int>();
	list.add(1);
	list.add(2);
	DS::List<int> list2 = DS::List<int>();
	list2 = std::move(list);

	EXPECT_EQ(list2.getSize(), 2);
	EXPECT_EQ(list2[0], 1);
	EXPECT_EQ(list2[1], 2);
}
