/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		if (lists.empty() || lists.size() == 0) {
			return nullptr;
		}

		for (int i = 1; i < lists.size(); i++) {
			lists[i] = mergeList(lists[i], lists[i - 1]);
		}
		return lists.back();
	}

	ListNode* mergeList(ListNode* left, ListNode* right) {
		ListNode* dummy = new ListNode(0);
		ListNode* tail = dummy;

		while (left && right) {
			if (left->val <= right->val) {
				tail->next = left;
				left = left->next;
			}
			else {
				tail->next = right;
				right = right->next;
			}
			tail = tail->next;
		}
		if (left) {
			tail->next = left;
		}
		if (right) {
			tail->next = right;
		}
		return dummy->next;
	}
};