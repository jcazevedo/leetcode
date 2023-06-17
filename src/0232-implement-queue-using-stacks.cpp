// 232. Implement Queue using Stacks
// https://leetcode.com/problems/implement-queue-using-stacks/

#include <stack>

using namespace std;

class MyQueue {
private:
  stack<int> in;
  stack<int> out;

  void transfer() {
    if (out.empty()) {
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
    }
  }

public:
  MyQueue() {}

  void push(int x) { in.push(x); }

  int pop() {
    transfer();
    int ans = out.top();
    out.pop();
    return ans;
  }

  int peek() {
    transfer();
    return out.top();
  }

  bool empty() { return in.empty() && out.empty(); }
};
