// 1089. Duplicate Zeros
// https://leetcode.com/problems/duplicate-zeros/

#include <vector>

using namespace std;

class Solution {
public:
  void duplicateZeros(vector<int>& arr) {
    int zeros = 0;
    for (int v : arr) {
      if (v == 0)
        zeros++;
    }
    int N = arr.size();
    for (int i = N - 1, target = N - 1 + zeros; i >= 0 && target >= 0;
         --i, --target) {
      arr[min(target, N - 1)] = arr[i];
      if (arr[i] == 0) {
        target--;
        arr[min(target, N - 1)] = arr[i];
      }
    }
  }
};
