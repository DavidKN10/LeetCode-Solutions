#include <queue>

class MyStack {
public:
    std::queue<int> q;

    MyStack() {}

    void push(int x) {
        if (q.size() == 0) {
            q.push(x);
        }
        else {
            q.push(x);
            for (int i = 0; i < q.size() - 1; i++) {
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }

    int pop() {
        int result = q.front();
        q.pop();
        return result;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        if (q.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};