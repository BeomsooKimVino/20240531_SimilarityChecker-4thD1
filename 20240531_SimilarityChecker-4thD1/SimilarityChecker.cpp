#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using std::string;
using std::pair;

struct Input {
	string str1;
	string str2;
};

class SimilarityChecker {
public:
	int GetLengthScore(Input input) {
		int strLength1 = static_cast<int>(input.str1.length());
		int strLength2 = static_cast<int>(input.str2.length());

		if (strLength1 == strLength2)
		{
			return 60;
		}
		else if (strLength1 >= strLength2 * 2
			|| strLength2 >= strLength1 * 2)
		{
			return 0;
		}
		else
		{
			return GetGapScore(strLength1, strLength2);
		}
	}

	int GetApperenceScore(Input input)
	{
		std::sort(input.str1.begin(), input.str1.end());
		std::sort(input.str2.begin(), input.str2.end());
		if (input.str1 == input.str2)
			return MAX_APPERENCE_SCORE;
		return 0;
	}

private:
	const int MAX_GAP_SCORE = 60;
	const int MAX_APPERENCE_SCORE = 40;
	int GetGapScore(int strLength1, int strLength2)
	{
		int gap = std::abs(strLength1 - strLength2);
		int minLength = std::min(strLength1, strLength2);
		double gapscoreRational = 1 - (static_cast<double>(gap) / minLength);
		return static_cast<int>(MAX_GAP_SCORE * gapscoreRational);
	}
};
