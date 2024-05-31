#include "pch.h"
#include "../20240531_SimilarityChecker-4thD1/SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker sc;
	void CheckLengthScore(Input input, int expected)
	{
		EXPECT_EQ(expected, sc.GetLengthScore(input));
	}
	void CheckApperenceScore(Input input, int expected)
	{
		EXPECT_EQ(expected, sc.GetApperenceScore(input));
	}
};

TEST_F(SimilarityCheckerFixture, SCLength60) {
	CheckLengthScore({ "ASD", "DSA" }, 60);
}

TEST_F(SimilarityCheckerFixture, SCLength0) {
	CheckLengthScore({ "A", "BB" }, 0);
}

TEST_F(SimilarityCheckerFixture, SCLengthGapScore20) {
	CheckLengthScore({ "AAABB", "BAA" }, 20);
}

TEST_F(SimilarityCheckerFixture, SCLengthGapScore30) {
	CheckLengthScore({ "AA", "AAE" }, 30);
}

TEST_F(SimilarityCheckerFixture, SCApperenceScore40) {
	CheckApperenceScore({ "ASD", "DSA" }, 40);
}

TEST_F(SimilarityCheckerFixture, SCApperenceScore0) {

	CheckApperenceScore({ "A", "BB" }, 0);
}

TEST_F(SimilarityCheckerFixture, SCApperenceScore40SameAlpha) {
	CheckApperenceScore({ "AAABB", "BA" }, 40);
}

TEST_F(SimilarityCheckerFixture, SCApperenceScorer20PartialScore) {
	CheckApperenceScore({ "AA", "AAB" }, 20);
}
