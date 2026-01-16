// 2975. Maximum Square Area by Removing Fences From a Field
// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/

#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    sort(hFences.begin(), hFences.end());
    hFences.insert(hFences.begin(), 1);
    hFences.push_back(m);
    sort(vFences.begin(), vFences.end());
    vFences.insert(vFences.begin(), 1);
    vFences.push_back(n);
    int H = hFences.size();
    int V = vFences.size();
    long long ans = -1L;
    unordered_set<int> hasWidth;
    for (int i = 0; i < V; ++i) {
      for (int j = i + 1; j < V; ++j) { hasWidth.insert(vFences[j] - vFences[i]); }
    }
    for (int i = 0; i < H; ++i) {
      for (int j = i + 1; j < H; ++j) {
        long long h = ((long long)hFences[j]) - hFences[i];
        if (hasWidth.count(h)) { ans = max(ans, h * h); }
      }
    }
    return ans % 1000000007;
  }
};
