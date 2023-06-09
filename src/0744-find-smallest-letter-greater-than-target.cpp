// 744. Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#include <vector>

using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int N = letters.size();
    int lo = 0, hi = N;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (letters[mid] <= target)
        lo = mid + 1;
      else
        hi = mid;
    }
    if (lo >= N)
      return letters[0];
    return letters[lo];
  }
};
