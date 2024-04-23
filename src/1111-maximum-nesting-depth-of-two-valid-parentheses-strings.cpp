// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
// https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> maxDepthAfterSplit(string seq) {
    int N = seq.size(), curr = 0;
    vector<int> ans(N);
    for (int i = 0; i < N; ++i) {
      if (seq[i] == '(') ++curr;
      ans[i] = curr % 2;
      if (seq[i] == ')') --curr;
    }
    return ans;
  }
};
