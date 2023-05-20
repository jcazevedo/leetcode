// 155. Min Stack
// https://leetcode.com/problems/min-stack/

#include <stack>

using namespace std;

class MinStack {
private:
  stack<pair<int, int>> inner;

public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (inner.empty() || inner.top().second > x) {
      inner.push(make_pair(x, x));
    } else {
      inner.push(make_pair(x, inner.top().second));
    }
  }

  void pop() { inner.pop(); }

  int top() { return inner.top().first; }

  int getMin() { return inner.top().second; }
};
