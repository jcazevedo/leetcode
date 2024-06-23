// 1997. First Day Where You Have Been in All the Rooms
// https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 public:
  int firstDayBeenInAllRooms(vector<int>& nextVisit) {
    int N = nextVisit.size();
    vector<long long> dp(N, -1L);
    dp[0] = 0L;
    for (int i = 1; i < N; ++i) { dp[i] = ((2L * dp[i - 1]) % MOD + MOD - dp[nextVisit[i - 1]] + 2L) % MOD; }
    return dp[N - 1];
  }
};
