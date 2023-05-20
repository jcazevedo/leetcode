// 275. H-Index II
// https://leetcode.com/problems/h-index-ii/

#include <vector>

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    if (citations.size() == 0)
      return 0;
    int lo = 0, hi = citations.size() - 1, N = citations.size();
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      int rem = N - citations[mid];
      if (rem < mid)
        hi = mid - 1;
      else
        lo = mid;
    }
    if (citations[hi] > N - hi)
      return N;
    if (citations[hi] == N - hi)
      return citations[hi];
    return N - hi - 1;
  }
};
