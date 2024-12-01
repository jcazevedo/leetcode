// 1346. Check if N and Its Double Exist
// https://leetcode.com/problems/check-if-n-and-its-double-exist/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> seen;
    for (int v : arr) {
      if (seen.count(v * 2) || (v % 2 == 0 && seen.count(v / 2))) { return true; }
      seen.insert(v);
    }
    return false;
  }
};
