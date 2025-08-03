#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
	bool isValid(std::string s) {
		std::stack<char> openBrackets;		
		if (s.empty()) {
			return false;
		}
		else if (s.length() == 1) {
			return false;
		}
		else if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
			return false;
		}
		for (size_t i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				openBrackets.push(s[i]);
				continue;
			}
			switch (s[i]) {
			case ')':
				if (openBrackets.empty() || openBrackets.top() != '(') {
					return false;
					break;
				}
				else {
					openBrackets.pop();
					break;
				}
			case '}':
				if (openBrackets.empty() || openBrackets.top() != '{') {
					return false;
					break;
				}
				else {
					openBrackets.pop();
					break;
				}
			case ']':
				if (openBrackets.empty() || openBrackets.top() != '[') {
					return false;
					break;
				}
				else {
					openBrackets.pop();
					break;
				}	
			}	
		}
		return openBrackets.empty();
	}
};