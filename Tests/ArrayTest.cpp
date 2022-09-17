#include "pch.h"
#include "Array.h"

TEST(Array, InitializeWithSizeZero) {
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->getSize(), 0);

	delete arr;
}

TEST(Array, InitializeWithCustomSize) {
	DS::Array<int>* arr = new DS::Array<int>(20);

	EXPECT_EQ(arr->getSize(), 20);

	delete arr;
}

TEST(Array, AddElement) {
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->getSize(), 0);
	arr->push(1);
	EXPECT_EQ(arr->getSize(), 1);
	arr->push(2);
	EXPECT_EQ(arr->getSize(), 2);

	delete arr;
}