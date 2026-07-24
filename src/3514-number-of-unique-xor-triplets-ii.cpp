// 3514. Number of Unique XOR Triplets II
// https://leetcode.com/problems/number-of-unique-xor-triplets-ii/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniqueXorTriplets(vector<int>& nums) {
    int largest = 0;
    for (int v : nums) { largest = max(v, largest); }
    int k = 1;
    while (k <= largest) { k <<= 1; }
    vector<bool> one(k), two(k), three(k);
    for (int v : nums) {
      one[v] = true;
      for (int i = 0; i < k; ++i) {
        if (one[i]) { two[v ^ i] = true; }
      }
    }
    for (int v : nums) {
      for (int i = 0; i < k; ++i) {
        if (two[i]) { three[v ^ i] = true; }
      }
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
      if (three[i]) { ++ans; }
    }
    return ans;
  }
};
