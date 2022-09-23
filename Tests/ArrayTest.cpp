#include "pch.h"
#include "Array.h"

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

	DS::Array<int> filteredArray = arr.filter([](int x) { return x % 2 == 0; });
	EXPECT_EQ(filteredArray.getSize(), 3);
	EXPECT_EQ(filteredArray[0], 2);
	EXPECT_EQ(filteredArray[1], 6);
	EXPECT_EQ(filteredArray[2], 6);
}

TEST(Array, FilterArrayEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	DS::Array<int> filteredArray = arr.filter([](int x) { return x % 2 == 0; });
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

	auto predicate = [](int x) { return x % 2 == 0; };
	EXPECT_TRUE(arr.any(predicate), true);
}

TEST(Array, ContainsNoElementFulfillingThePredicate)
{
	DS::Array<int> arr = DS::Array<int>();
	arr.push(1);
	arr.push(2);
	arr.push(3);
	arr.push(4);

	auto predicate = [](int x) { return x == 0; };
	EXPECT_FALSE(arr.any(predicate));
}

TEST(Array, ContainsOneElementFulfillingThePredicateInEmptyArray)
{
	DS::Array<int> arr = DS::Array<int>();

	auto predicate = [](int x) { return x == 0; };
	EXPECT_FALSE(arr.any(predicate), false);
}
