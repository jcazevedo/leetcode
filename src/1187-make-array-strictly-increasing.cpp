// 1187. Make Array Strictly Increasing
// https://leetcode.com/problems/make-array-strictly-increasing/

#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 private:
  int getNext(const vector<int>& arr, int value) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] <= value)
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }

  map<pair<int, int>, int> cache;

  int minOps(int i,
             int prev,
             const vector<int>& arr1,
             const vector<int>& arr2) {
    if (i == (int)arr1.size()) return 0;
    pair<int, int> key = make_pair(i, prev);
    if (cache.find(key) == cache.end()) {
      cache[key] = -1;
      if (arr1[i] > prev) cache[key] = minOps(i + 1, arr1[i], arr1, arr2);
      int toSwap = getNext(arr2, prev);
      if (toSwap < (int)arr2.size()) {
        int nextSwapCost = minOps(i + 1, arr2[toSwap], arr1, arr2);
        if (nextSwapCost != -1 &&
            (cache[key] == -1 || (nextSwapCost + 1) < cache[key]))
          cache[key] = 1 + nextSwapCost;
      }
    }
    return cache[key];
  }

 public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end());
    return minOps(0, -1, arr1, arr2);
  }
};
