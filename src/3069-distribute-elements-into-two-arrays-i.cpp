// 3069. Distribute Elements Into Two Arrays I
// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1, arr2;
    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);
    int n = nums.size();
    for (int i = 2; i < n; ++i) {
      if (arr1.back() > arr2.back()) {
        arr1.push_back(nums[i]);
      } else {
        arr2.push_back(nums[i]);
      }
    }
    for (int num : arr2) { arr1.push_back(num); }
    return arr1;
  }
};
