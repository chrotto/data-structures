#include "pch.h"
#include "Array.h"

TEST(Array, InitializeWithSizeZero)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->getSize(), 0);

	delete arr;
}

TEST(Array, InitializeWithCustomSize)
{
	DS::Array<int>* arr = new DS::Array<int>(20);

	EXPECT_EQ(arr->getSize(), 20);

	delete arr;
}

TEST(Array, AddElement)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->getSize(), 0);
	arr->push(1);
	EXPECT_EQ(arr->getSize(), 1);
	arr->push(2);
	EXPECT_EQ(arr->getSize(), 2);

	delete arr;
}

TEST(Array, IndexOperatorAccess)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);
	arr->push(20);
	arr->push(30);

	EXPECT_EQ((*arr)[0], 10);
	EXPECT_EQ((*arr)[1], 20);
	EXPECT_EQ((*arr)[2], 30);
}

TEST(Array, IndexOperatorAccessOutOfRange)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);

	EXPECT_THROW((*arr)[1], DS::OutOfRangeException);
	EXPECT_THROW((*arr)[-1], DS::OutOfRangeException);
}

TEST(Array, FirstElementAccess)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);
	arr->push(20);

	EXPECT_EQ(arr->first(), 10);
}

TEST(Array, FirstElementAccessWithNoSuchElementException)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_THROW(arr->first(), DS::NoSuchElementException);
}

TEST(Array, FirstOrNullElementAccessOfExistingElement)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);
	arr->push(20);

	EXPECT_EQ(*arr->firstOrNull(), 10);
}

TEST(Array, FirstOrNullElementAccessOfEmptyArray)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->firstOrNull(), nullptr);
}

TEST(Array, LastElementAccess)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);
	arr->push(20);

	EXPECT_EQ(arr->last(), 20);
}

TEST(Array, LastElementAccessWithNoSuchElementException)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_THROW(arr->last(), DS::NoSuchElementException);
}

TEST(Array, LastOrNullElementAccessOfExistingElement)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);
	arr->push(20);

	EXPECT_EQ(*arr->lastOrNull(), 20);
}

TEST(Array, LastOrNullElementAccessOfEmptyArray)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->lastOrNull(), nullptr);
}

TEST(Array, EmptyCheckOnEmptyArray)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->isEmpty(), true);
}

TEST(Array, EmptyCheckOnNonEmptyArray)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);

	EXPECT_EQ(arr->isEmpty(), false);
}

TEST(Array, ContainsElement)
{
	DS::Array<int>* arr = new DS::Array<int>();
	arr->push(10);
	arr->push(20);
	arr->push(30);

	EXPECT_TRUE(arr->contains(10));
	EXPECT_TRUE(arr->contains(20));
	EXPECT_TRUE(arr->contains(30));
	EXPECT_FALSE(arr->contains(40));
}

TEST(Array, ContainsElementInEmptyArry)
{
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_FALSE(arr->contains(10));
}
