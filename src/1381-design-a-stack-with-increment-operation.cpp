// 1381. Design a Stack With Increment Operation
// https://leetcode.com/problems/design-a-stack-with-increment-operation/

#include <algorithm>
#include <vector>

using namespace std;

class CustomStack {
 private:
  vector<int> stack;
  int len;

 public:
  CustomStack(int maxSize) {
    stack = vector<int>(maxSize);
    len = 0;
  }

  void push(int x) {
    if (len < (int)stack.size()) { stack[len++] = x; }
  }

  int pop() {
    if (len == 0) { return -1; }
    int ans = stack[len - 1];
    --len;
    return ans;
  }

  void increment(int k, int val) {
    for (int i = 0; i < min(k, len); ++i) { stack[i] += val; }
  }
};
