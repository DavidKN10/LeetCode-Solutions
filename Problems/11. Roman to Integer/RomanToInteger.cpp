#include <string>
#include <map>

class Solution {
public: 
	std::map<std::string, int> conversion = { 
		{"I", 1},
		{"V", 5},
		{"X", 10},
		{"L", 50},
		{"C", 100},
		{"D", 500},
		{"M", 1000} 
	};

	int romanToInt(std::string s) {
		std::string romanNumeral;
		std::string secondRomanNumeral;
		int sum = 0;
		
		for (size_t i = 0 ; i < s.size(); i++) {
			romanNumeral = s[i];
			secondRomanNumeral = s[i + 1];
			if (i < s.length() - 1 && conversion.at(romanNumeral) < conversion.at(secondRomanNumeral)) {
				sum -= conversion.at(romanNumeral);
			}
			else {
				sum += conversion.at(romanNumeral);
			}	
		}
		return sum;
	}
};