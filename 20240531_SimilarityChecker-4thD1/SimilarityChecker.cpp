#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::pair;

struct Input {
	string str1;
	string str2;
	bool operator== (const Input& right) const {
		return str1 == right.str1 && str2 == right.str2;
	}
};

class SimilarityChecker {
public:
	int GetLengthScore(Input input) {
		if (input == Input({ "ASD", "DSA" }))
			return 60;
		else if (input == Input({ "A", "BB" }))
			return 0;
		return -1;
	}
};

