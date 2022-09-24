#include "pch.h"
#include "Array.h"
#include <string>

TEST(Array, InitializeWithSizeZero)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_EQ(arr.getSize(), 0);
}

TEST(Array, InitializeWithCustomSize)
{
	DS::Array<int> arr = DS::Array<int>(20);

	EXPECT_EQ(arr.getSize(), 20);
}

TEST(Array, AddElement)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_EQ(arr.getSize(), 0);
	arr.push(1);
	EXPECT_EQ(arr.getSize(), 1);
	arr.push(2);
	EXPECT_EQ(arr.getSize(), 2);
}

TEST(Array, IndexOperatorAccess)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);
	arr.push(20);
	arr.push(30);

	EXPECT_EQ(arr[0], 10);
	EXPECT_EQ(arr[1], 20);
	EXPECT_EQ(arr[2], 30);
}

TEST(Array, IndexOperatorAccessOutOfRange)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);

	EXPECT_THROW(arr[1], DS::OutOfRangeException);
	EXPECT_THROW(arr[-1], DS::OutOfRangeException);
}

TEST(Array, FirstElementAccess)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);
	arr.push(20);

	EXPECT_EQ(arr.first(), 10);
}

TEST(Array, FirstElementAccessWithNoSuchElementException)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_THROW(arr.first(), DS::NoSuchElementException);
}

TEST(Array, FirstOrNullElementAccessOfExistingElement)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);
	arr.push(20);

	EXPECT_EQ(*arr.firstOrNull(), 10);
}

TEST(Array, FirstOrNullElementAccessOfEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_EQ(arr.firstOrNull(), nullptr);
}

TEST(Array, LastElementAccess)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);
	arr.push(20);

	EXPECT_EQ(arr.last(), 20);
}

TEST(Array, LastElementAccessWithNoSuchElementException)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_THROW(arr.last(), DS::NoSuchElementException);
}

TEST(Array, LastOrNullElementAccessOfExistingElement)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);
	arr.push(20);

	EXPECT_EQ(*arr.lastOrNull(), 20);
}

TEST(Array, LastOrNullElementAccessOfEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_EQ(arr.lastOrNull(), nullptr);
}

TEST(Array, EmptyCheckOnEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_EQ(arr.isEmpty(), true);
}

TEST(Array, EmptyCheckOnNonEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);

	EXPECT_EQ(arr.isEmpty(), false);
}

TEST(Array, ContainsElement)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(10);
	arr.push(20);
	arr.push(30);

	EXPECT_TRUE(arr.contains(10));
	EXPECT_TRUE(arr.contains(20));
	EXPECT_TRUE(arr.contains(30));
	EXPECT_FALSE(arr.contains(40));
}

TEST(Array, ContainsElementInEmptyArry)
{
	DS::Array<int> arr = DS::Array<int>();

	EXPECT_FALSE(arr.contains(10));
}

TEST(Array, FilterArrayByEvenNumbers)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	arr.push(5);
	arr.push(6);
	arr.push(6);

	DS::Array<int> filteredArray = arr.filter([](const int& x) { return x % 2 == 0; });
	EXPECT_EQ(filteredArray.getSize(), 3);
	EXPECT_EQ(filteredArray[0], 2);
	EXPECT_EQ(filteredArray[1], 6);
	EXPECT_EQ(filteredArray[2], 6);
}

TEST(Array, FilterArrayEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	DS::Array<int> filteredArray = arr.filter([](const int& x) { return x % 2 == 0; });
	EXPECT_EQ(filteredArray.getSize(), 0);
}

TEST(Array, CopyAssignmentOperator)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	DS::Array<int> arr2 = DS::Array<int>();
	arr2 = arr;

	EXPECT_EQ(arr.getSize(), 2);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr2.getSize(), 2);
	EXPECT_EQ(arr2[0], 1);
	EXPECT_EQ(arr2[1], 2);
}

TEST(Array, MoveAssignmentOperator)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	DS::Array<int> arr2 = DS::Array<int>();
	arr2 = std::move(arr);

	EXPECT_EQ(arr2.getSize(), 2);
	EXPECT_EQ(arr2[0], 1);
	EXPECT_EQ(arr2[1], 2);
}

TEST(Array, ArrayPlusOperator)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	DS::Array<int> arr2 = DS::Array<int>();
	arr2.push(2);
	arr2.push(3);

	DS::Array<int> arr3 = arr + arr2;

	EXPECT_EQ(arr3.getSize(), 3);
	EXPECT_EQ(arr3[0], 1);
	EXPECT_EQ(arr3[1], 2);
	EXPECT_EQ(arr3[2], 3);
}

TEST(Array, ArrayPlusEqualsOperator)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	DS::Array<int> arr2 = DS::Array<int>();
	arr2.push(2);
	arr2.push(3);

	arr2 += arr;

	EXPECT_EQ(arr2.getSize(), 3);
	EXPECT_EQ(arr2[0], 2);
	EXPECT_EQ(arr2[1], 3);
	EXPECT_EQ(arr2[2], 1);
}

TEST(Array, ContainsOneElementFulfillingThePredicate)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	arr.push(3);
	arr.push(4);

	auto predicate = [](const int& x) { return x % 2 == 0; };
	EXPECT_TRUE(arr.any(predicate));
}

TEST(Array, ContainsNoElementFulfillingThePredicate)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	arr.push(3);
	arr.push(4);

	auto predicate = [](const int& x) { return x == 0; };
	EXPECT_FALSE(arr.any(predicate));
}

TEST(Array, ContainsOneElementFulfillingThePredicateInEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	auto predicate = [](const int& x) { return x == 0; };
	EXPECT_FALSE(arr.any(predicate));
}

TEST(Array, MapArrayOfEvenNumbersToOddNumbers)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(2);
	arr.push(4);
	arr.push(6);
	arr.push(8);

	auto transform = [](int x) {return x + 1; };
	DS::Array<int> mappedArray = arr.map<int>(transform);

	EXPECT_EQ(arr[0], 2);
	EXPECT_EQ(arr[1], 4);
	EXPECT_EQ(arr[2], 6);
	EXPECT_EQ(arr[3], 8);

	EXPECT_EQ(mappedArray[0], 3);
	EXPECT_EQ(mappedArray[1], 5);
	EXPECT_EQ(mappedArray[2], 7);
	EXPECT_EQ(mappedArray[3], 9);
}

TEST(Array, MapArrayOfIntsToStrings)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(2);
	arr.push(4);
	arr.push(6);
	arr.push(8);

	auto transform = [](int x) {return std::to_string(x); };
	DS::Array<std::string> mappedArray = arr.map<std::string>(transform);

	EXPECT_EQ(arr[0], 2);
	EXPECT_EQ(arr[1], 4);
	EXPECT_EQ(arr[2], 6);
	EXPECT_EQ(arr[3], 8);

	EXPECT_EQ(mappedArray[0], "2");
	EXPECT_EQ(mappedArray[1], "4");
	EXPECT_EQ(mappedArray[2], "6");
	EXPECT_EQ(mappedArray[3], "8");
}

TEST(Array, MapOfEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	auto transform = [](int x) {return x + 1; };
	DS::Array<int> mappedArray = arr.map<int>(transform);

	EXPECT_TRUE(mappedArray.isEmpty());
}

TEST(Array, ReduceEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_THROW(arr.reduce(operation), DS::UnsupportedOperationException);
}

TEST(Array, ReduceArrayWithOneElement)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(arr.reduce(operation), 1);
}

TEST(Array, ReduceArrayWithMultipleElements)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	arr.push(3);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(arr.reduce(operation), 6);
}

TEST(Array, FoldEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(arr.fold<int>(operation, 0), 0);
}

TEST(Array, FoldArrayWithOneElement)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(arr.fold<int>(operation, 4), 5);
}

TEST(Array, FoldArrayWithMultipleElements)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	arr.push(3);
	auto operation = [](int acc, const int& x) { return acc + x; };

	EXPECT_EQ(arr.fold<int>(operation, 4), 10);
}

TEST(Array, FindElementInEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();
	auto predicate = [](const int& x) { return x % 2 == 0; };

	EXPECT_EQ(arr.find(predicate), nullptr);
}

TEST(Array, FindElementInArray)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	arr.push(3);
	auto predicate = [](const int& x) { return x % 2 == 0; };

	EXPECT_EQ(*arr.find(predicate), 2);
}

TEST(Array, SortEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();
	auto comparison = [](const int& x, const int& y) { return x < y; };
	DS::Array sortedArr = arr.sort(comparison);

	EXPECT_EQ(sortedArr.getSize(), 0);
}

TEST(Array, SortArray)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(5);
	arr.push(10);
	arr.push(1);
	arr.push(4);
	arr.push(8);
	auto comparison = [](const int& x, const int& y) { return x < y; };
	DS::Array sortedArr = arr.sort(comparison);

	EXPECT_EQ(arr[0], 5);
	EXPECT_EQ(arr[1], 10);
	EXPECT_EQ(arr[2], 1);
	EXPECT_EQ(arr[3], 4);
	EXPECT_EQ(arr[4], 8);

	EXPECT_EQ(sortedArr[0], 1);
	EXPECT_EQ(sortedArr[1], 4);
	EXPECT_EQ(sortedArr[2], 5);
	EXPECT_EQ(sortedArr[3], 8);
	EXPECT_EQ(sortedArr[4], 10);
}
