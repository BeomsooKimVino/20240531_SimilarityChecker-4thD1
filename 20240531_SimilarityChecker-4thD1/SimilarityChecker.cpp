#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>

using std::string;
using std::unordered_set;
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

		int longerLength = std::max(strLength1, strLength2);
		int shorterLength = std::min(strLength1, strLength2);

		if (longerLength == shorterLength)
			return MAX_APPERENCE_SCORE;
		else if (longerLength >= shorterLength * 2)
			return 0;
		else
			return GetGapScore(longerLength, shorterLength);
	}

	int GetApperenceScore(Input input)
	{
		unordered_set<char> usedAlpha1 = GetUsedUniqueAlphaSet(input.str1);
		unordered_set<char> usedAlpha2 = GetUsedUniqueAlphaSet(input.str2);

		pair<int, int> alphaCnt = GetAlphaCnt(usedAlpha1, usedAlpha2);
		int totalAlphaCnt = alphaCnt.first;
		int samelAlphaCnt = alphaCnt.second;

		return (MAX_APPERENCE_SCORE * static_cast<double>(samelAlphaCnt) / totalAlphaCnt);
	}

private:
	const int MAX_GAP_SCORE = 60;
	const int MAX_APPERENCE_SCORE = 40;

	int GetGapScore(int longerLength, int shorterLength)
	{
		int gap = longerLength - shorterLength;
		double gapscore = MAX_GAP_SCORE * (shorterLength - static_cast<double>(gap)) / shorterLength;
		return static_cast<int>(gapscore);
	}

	bool IsNotApperence(std::unordered_set<char>& usedAlpha, char& used)
	{
		return usedAlpha.find(used) == usedAlpha.end();
	}

	std::unordered_set<char> GetUsedUniqueAlphaSet(string& str)
	{
		std::unordered_set<char> usedAlpha;
		for (char& used : str)
		{
			usedAlpha.insert(used);
		}
		return usedAlpha;
	}

	pair<int, int> GetAlphaCnt(std::unordered_set<char>& usedAlpha2, std::unordered_set<char>& usedAlpha1)
	{
		int totalAlphaCnt = usedAlpha1.size();
		int samelAlphaCnt = 0;
		for (char used : usedAlpha2)
		{
			if (IsNotApperence(usedAlpha1, used)) totalAlphaCnt++;
			else samelAlphaCnt++;
		}
		return { totalAlphaCnt, samelAlphaCnt };
	}

};
