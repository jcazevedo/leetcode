#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int N = nums.size();
    multiset<int> curr;
    for (int i = 0; i < k; ++i)
      curr.insert(nums[i]);
    vector<int> ans;
    ans.push_back(*curr.rbegin());
    for (int i = k; i < N; ++i) {
      curr.erase(curr.find(nums[i - k]));
      curr.insert(nums[i]);
      ans.push_back(*curr.rbegin());
    }
    return ans;
  }
};
