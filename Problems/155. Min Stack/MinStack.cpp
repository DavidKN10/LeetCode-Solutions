#include <stack>

class MinStack {
public:
	std::stack<int> stack;
	std::stack<int> minValues;

	MinStack() {}

	void push(int val) {
		stack.push(val);
		if (!minValues.empty()) {
			val = std::min(val, minValues.top());
		}
		minValues.push(val);
	}

	void pop() {
		stack.pop();
		minValues.pop();
	}

	int top() {
		return stack.top();
	}

	int getMin() {
		return minValues.top();
	}
};