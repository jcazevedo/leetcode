// 3514. Number of Unique XOR Triplets II
// https://leetcode.com/problems/number-of-unique-xor-triplets-ii/

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniqueXorTriplets(vector<int>& nums) {
    int N = nums.size();
    unordered_set<int> pairs;
    for (int i = 0; i < N; ++i) {
      for (int j = i; j < N; ++j) { pairs.insert(nums[i] ^ nums[j]); }
    }
    unordered_set<int> triplets;
    for (int i = 0; i < N; ++i) {
      for (int p : pairs) { triplets.insert(nums[i] ^ p); }
    }
    return triplets.size();
  }
};
