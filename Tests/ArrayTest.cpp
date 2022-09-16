#include "pch.h"
#include "Array.h"

TEST(Array, InitializeWithDefaultSizeTen) {
	DS::Array<int>* arr = new DS::Array<int>();

	EXPECT_EQ(arr->getSize(), 10);

	delete arr;
}

TEST(Array, InitializeWithCustomSize) {
	DS::Array<int>* arr = new DS::Array<int>(20);

	EXPECT_EQ(arr->getSize(), 20);

	delete arr;
}