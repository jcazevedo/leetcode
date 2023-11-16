// 1980. Find Unique Binary String
// https://leetcode.com/problems/find-unique-binary-string/

#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  string dfs(string curr, int N, const set<string>& nums) {
    if ((int)curr.size() == N) {
      if (nums.find(curr) == nums.end())
        return curr;
      return "";
    }

    for (char ch = '0'; ch <= '1'; ++ch) {
      string next = dfs(curr + ch, N, nums);
      if (next != "")
        return next;
    }

    return "";
  }

public:
  string findDifferentBinaryString(vector<string>& nums) {
    set<string> numsSet;
    for (string num : nums)
      numsSet.insert(num);

    return dfs("", nums.size(), numsSet);
  }
};
