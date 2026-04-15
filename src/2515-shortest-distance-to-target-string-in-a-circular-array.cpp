// 2515. Shortest Distance to Target String in a Circular Array
// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    for (int j = 0; j < n; ++j) {
      if (words[(startIndex + j) % n] == target) { return j; }
      if (words[(startIndex + n - j) % n] == target) { return j; }
    }
    return -1;
  }
};
