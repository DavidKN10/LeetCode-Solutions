#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string answer = "";
        std::sort(strs.begin(), strs.end());
        std::string first = strs.front();
        std::string last = strs.back();
        
        for (size_t i = 0; i < std::min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                return answer;
            }
            answer += first[i];
        }
        return answer;
    }
};