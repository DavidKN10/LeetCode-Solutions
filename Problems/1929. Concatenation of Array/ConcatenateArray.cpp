#include <vector>

class Solution {
public:
	std::vector<int> getConcatenation(std::vector<int>& nums) {
		std::vector<int> ans;
		for (int i = 0; i <= nums.size() - 1; i++) {
			ans.push_back(nums[i]);
			ans.insert(ans.begin() + i, nums[i]);
		}
		return ans;
	}
};