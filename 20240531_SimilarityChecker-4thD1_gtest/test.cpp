#include "pch.h"
#include "../20240531_SimilarityChecker-4thD1/SimilarityChecker.cpp"

TEST(SimilarityCheckerSuite, SCLength60) {
	SimilarityChecker sc;
	Input input = { "ASD", "DSA" };
	int expected = 60;
	EXPECT_EQ(expected, sc.GetLengthScore(input));
}

TEST(SimilarityCheckerSuite, SCLength0) {
	SimilarityChecker sc;
	Input input = { "A", "BB" };
	int expected = 0;
	EXPECT_EQ(expected, sc.GetLengthScore(input));
}

TEST(SimilarityCheckerSuite, SCLengthGapScore20) {
	SimilarityChecker sc;
	Input input = { "AAABB", "BAA" };
	int expected = 20;
	EXPECT_EQ(expected, sc.GetLengthScore(input));
}
