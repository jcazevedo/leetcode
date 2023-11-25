// 228. Summary Ranges
// https://leetcode.com/problems/summary-ranges/

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  string toRange(int start, int end) {
    ostringstream ss;
    if (start == end)
      ss << start;
    else
      ss << start << "->" << end;
    return ss.str();
  }

 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) return vector<string>();
    int start = nums[0], end = nums[0];
    vector<string> ans;
    for (int i = 1; i < (int)nums.size(); ++i) {
      if ((long long)nums[i] - end == 1)
        end = nums[i];
      else {
        ans.push_back(toRange(start, end));
        start = end = nums[i];
      }
    }
    ans.push_back(toRange(start, end));
    return ans;
  }
};
