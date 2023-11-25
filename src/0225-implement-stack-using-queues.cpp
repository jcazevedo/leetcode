// 225. Implement Stack using Queues
// https://leetcode.com/problems/implement-stack-using-queues/

#include <queue>

using namespace std;

class MyStack {
private:
  queue<int> stack;
  queue<int> tmp;

public:
  MyStack() {}

  void push(int x) { stack.push(x); }

  int pop() {
    while (stack.size() != 1) {
      tmp.push(stack.front());
      stack.pop();
    }
    int ans = stack.front();
    stack.pop();
    while (!tmp.empty()) {
      stack.push(tmp.front());
      tmp.pop();
    }
    return ans;
  }

  int top() {
    while (stack.size() != 1) {
      tmp.push(stack.front());
      stack.pop();
    }
    int ans = stack.front();
    stack.pop();
    tmp.push(ans);
    while (!tmp.empty()) {
      stack.push(tmp.front());
      tmp.pop();
    }
    return ans;
  }

  bool empty() { return stack.empty(); }
};
