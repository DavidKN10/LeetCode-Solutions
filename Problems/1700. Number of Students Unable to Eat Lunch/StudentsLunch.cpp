#include <vector>
#include <queue>

class Solution {
public:

	int countStudents(std::vector<int>& students, std::vector<int>& sandwhiches) {
		int n = students.size();
		std::queue<int> studentQueue;
		for (int student : students) {
			studentQueue.push(student);
		}

		for (int sandwhich : sandwhiches) {
			int count = 0;
			while (count < n && studentQueue.front() != sandwhich) {
				studentQueue.push(studentQueue.front());
				studentQueue.pop();
				count++;
			}

			if (studentQueue.front() == sandwhich) {
				studentQueue.pop();
				n--;
			}
			else {
				break;
			}
		}
		return n;
	}
};