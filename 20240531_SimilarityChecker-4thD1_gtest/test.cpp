#include "pch.h"
#include "../20240531_SimilarityChecker-4thD1/SimilarityChecker.cpp"

TEST(SimilarityCheckerSuite, SCLength60) {
	SimilarityChecker sc;
	Input input = { "ASD", "DSA" };
	int expected = 60;
	EXPECT_EQ(expected, sc.GetLengthScore(input));
}
