#include "pch.h"
#include "Set.h"

TEST(Set, InitializeWithSizeZero)
{
	DS::Set<int> set = DS::Set<int>();

	EXPECT_EQ(set.getSize(), 0);
}