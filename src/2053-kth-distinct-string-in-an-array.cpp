// 2053. Kth Distinct String in an Array
// https://leetcode.com/problems/kth-distinct-string-in-an-array/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> cnt, ord;
    for (const string& s : arr) { ++cnt[s]; }
    int idx = 0;
    for (const string& s : arr) {
      if (cnt[s] == 1 && ord.find(s) == ord.end()) { ord[s] = idx++; }
    }
    for (unordered_map<string, int>::iterator itr = cnt.begin(); itr != cnt.end(); ++itr) {
      if (itr->second == 1 && ord[itr->first] == k - 1) { return itr->first; }
    }
    return "";
  }
};
