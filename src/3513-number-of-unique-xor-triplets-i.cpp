// 3513. Number of Unique XOR Triplets I
// https://leetcode.com/problems/number-of-unique-xor-triplets-i/

#include <vector>

using namespace std;

class Solution {
 public:
  int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) { return n; }
    int answer = 1;
    while (answer <= n) { answer <<= 1; }
    return answer;
  }
};
