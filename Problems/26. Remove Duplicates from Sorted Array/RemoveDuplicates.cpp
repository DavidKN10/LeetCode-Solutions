#include <vector>

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		int leftPointer = 1;
	    for (int rightPointer = 1; rightPointer <= nums.size() - 1; rightPointer++) {
			if (nums.at(rightPointer) != nums.at(rightPointer - 1)) {
				nums[leftPointer] = nums[rightPointer];
				leftPointer++;
			}
	    }
	    return leftPointer;
	}
};
