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
		std::sort(input.str1.begin(), input.str1.end());
		std::sort(input.str2.begin(), input.str2.end());

		if (input.str1 == input.str2)
			return 60;
		else
			return 0;
	}
};

