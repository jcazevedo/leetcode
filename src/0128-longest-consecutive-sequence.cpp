// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  unordered_set<int> elems;
  unordered_map<int, int> cnt;

  int build_len(int num) {
    if (cnt.count(num) > 0) return cnt[num];
    if (elems.count(num) == 0) return 0;
    elems.erase(num);
    cnt[num] = 1 + build_len(num + 1);
    return cnt[num];
  }

 public:
  int longestConsecutive(vector<int>& nums) {
    elems.clear();
    cnt.clear();
    for (int num : nums) elems.insert(num);
    int best = 0;
    while (elems.size()) {
      int start = *elems.begin();
      int next = build_len(start);
      if (next > best) best = next;
    }
    return best;
  }
};
