class Solution {
public:
	void sortColors(std::vector<int>& nums) {
		std::vector<int> counts = { 0, 0, 0 };
		for (int item : nums) {
			counts[item]++;
		}

		int i = 0;
		for (int n = 0; n < counts.size(); n++) {
			for (int j = 0; j < counts[n]; j++) {
				nums[i] = n;
				i++;
			}
		}
	}
};