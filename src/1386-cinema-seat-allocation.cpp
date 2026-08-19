// 1386. Cinema Seat Allocation
// https://leetcode.com/problems/cinema-seat-allocation/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> reserved;
    for (vector<int>& seat : reservedSeats) {
      if (seat[1] >= 2 && seat[1] <= 9) { reserved[seat[0]] |= 1 << seat[1]; }
    }
    const int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
    const int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    const int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
    int ans = 2 * n;
    for (const pair<const int, int>& row : reserved) {
      bool canUseLeft = (row.second & left) == 0;
      bool canUseMiddle = (row.second & middle) == 0;
      bool canUseRight = (row.second & right) == 0;
      ans -= 2;
      if (canUseLeft && canUseRight) {
        ans += 2;
      } else if (canUseLeft || canUseMiddle || canUseRight) {
        ans += 1;
      }
    }
    return ans;
  }
};
