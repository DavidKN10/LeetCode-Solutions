#include <vector>
#include <algorithm>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> output;
		std::vector<int> emptyVector;
		
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					output.push_back(i);
					output.push_back(j);
					return output;
				}
			}
		}
		return emptyVector;
	}
};