// 969. Pancake Sorting
// https://leetcode.com/problems/pancake-sorting/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> pancakeSort(vector<int>& arr) {
    int N = arr.size();
    vector<int> ans;
    for (int i = N - 1; i >= 0; --i) {
      int target = i + 1;
      auto itr = arr.begin();
      for (int j = 0; j <= i; ++j) {
        if (arr[j] == target) {
          ans.push_back(j + 1);
          reverse(arr.begin(), ++itr);
          break;
        }
        itr++;
      }
      itr = arr.begin();
      for (int j = 0; j <= i; ++j)
        itr++;
      ans.push_back(target);
      reverse(arr.begin(), itr);
    }
    return ans;
  }
};
