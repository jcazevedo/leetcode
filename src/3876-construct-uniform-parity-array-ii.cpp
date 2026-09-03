// 3876. Construct Uniform Parity Array II
// https://leetcode.com/problems/construct-uniform-parity-array-ii/

#include <set>
#include <vector>

using namespace std;

class Solution {
 private:
  bool allEven(const vector<int>& nums1, const set<int>& odds) {
    for (int num : nums1) {
      if (num % 2 == 1) {
        set<int>::iterator itr = odds.lower_bound(num);
        if (itr == odds.begin()) { return false; }
      }
    }
    return true;
  }

  bool allOdd(const vector<int>& nums1, const set<int>& odds) {
    for (int num : nums1) {
      if (num % 2 == 0) {
        set<int>::iterator itr = odds.lower_bound(num);
        if (itr == odds.begin()) {
          if (*odds.begin() >= num) { return false; }
        }
      }
    }
    return true;
  }

 public:
  bool uniformArray(vector<int>& nums1) {
    set<int> odds;
    for (int num : nums1) {
      if (num % 2 == 1) { odds.insert(num); }
    }
    return allEven(nums1, odds) || allOdd(nums1, odds);
  }
};
