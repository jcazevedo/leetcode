// 2197. Replace Non-Coprime Numbers in Array
// https://leetcode.com/problems/replace-non-coprime-numbers-in-array/

#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 private:
  int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }

 public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    stack<long long> s;
    for (long long num : nums) {
      while (!s.empty()) {
        int g = gcd(s.top(), num);
        if (g == 1) { break; }
        num = (s.top() * num) / g;
        s.pop();
      }
      s.push(num);
    }
    vector<int> ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
