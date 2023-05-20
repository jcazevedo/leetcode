// 658. Find K Closest Elements
// https://leetcode.com/problems/find-k-closest-elements/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int N = arr.size();
    int lo = 0, hi = N;
    while (lo < hi) {
      int mid = (hi + lo) / 2;
      if (arr[mid] >= x) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    if (lo >= N)
      --lo;
    if (arr[lo] != x && lo > 0 && abs(x - arr[lo - 1]) <= abs(x - arr[lo]))
      --lo;
    vector<int> ans = {arr[lo]};
    int left = lo - 1;
    int right = lo + 1;
    while ((int)ans.size() < k) {
      if (left < 0 && right < N) {
        ans.push_back(arr[right]);
        right++;
      } else if (right >= N && left >= 0) {
        ans.push_back(arr[left]);
        left--;
      } else if (left < 0 && right >= N) {
        break;
      } else if (abs(x - arr[left]) <= abs(x - arr[right])) {
        ans.push_back(arr[left]);
        left--;
      } else {
        ans.push_back(arr[right]);
        right++;
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
