#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.empty() || k == 0)
      return false;
    multiset<int> current;
    current.insert(nums[0]);
    int N = nums.size();
    for (int i = 1; i < N; ++i) {
      auto l_itr = current.lower_bound(nums[i]);
      if (l_itr != current.end() &&
          abs(((long long) *l_itr) - ((long long) nums[i])) <= t)
        return true;
      if (l_itr != current.begin() &&
          abs(((long long) *(--l_itr)) - ((long long) nums[i])) <= t)
        return true;
      current.insert(nums[i]);
      if (current.size() > k)
        current.erase(current.find(nums[i - k]));
    }
    return false;
  }
};
