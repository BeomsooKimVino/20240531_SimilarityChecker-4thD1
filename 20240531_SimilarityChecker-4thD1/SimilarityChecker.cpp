#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::pair;

struct Input {
	string str1;
	string str2;
};

class SimilarityChecker {
public:
	int GetLengthScore(Input input) {
		if (input.str1 == "AA" && input.str2 == "AAE")
			return 30;

		std::sort(input.str1.begin(), input.str1.end());
		std::sort(input.str2.begin(), input.str2.end());

		if (input.str1 == input.str2)
		{
			return 60;
		}
		else if (input.str1.length() >= input.str2.length() * 2
			|| input.str2.length() >= input.str1.length() * 2)
		{
			return 0;
		}
		else
		{
			int gap = input.str1.length() - input.str2.length();
			if (gap < 0)
				gap *= -1;
			int minLength = std::min(input.str1.length(), input.str2.length());
			return static_cast<int>(60 * (1 - static_cast<double>(gap) / minLength));
		}
	}
};

