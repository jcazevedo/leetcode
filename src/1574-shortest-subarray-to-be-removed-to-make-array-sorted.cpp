// 1574. Shortest Subarray to be Removed to Make Array Sorted
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int N = arr.size();
    int r = N - 1;
    while (r > 0 && arr[r] >= arr[r - 1]) { --r; }
    int ans = r;
    int l = 0;
    while (l < r && (l == 0 || arr[l - 1] <= arr[l])) {
      while (r < N && arr[l] > arr[r]) { ++r; }
      ans = min(ans, r - l - 1);
      ++l;
    }
    return ans;
  }
};
