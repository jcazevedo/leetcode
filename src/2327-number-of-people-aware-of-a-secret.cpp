// 2327. Number of People Aware of a Secret
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

#include <vector>

using namespace std;

#define MOD 1000000007

class Solution {
 private:
  int modAdd(long long a, long long b) { return (a + b) % MOD; }

  int modSub(long long a, long long b) { return (a + MOD - b) % MOD; }

 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<int> sharing(n + 1, 0), discovered(n + 1, 0), knowing(n + 1, 0);
    sharing[1] = 0, discovered[1] = 1, knowing[1] = 1;
    for (int i = 2; i <= n; ++i) {
      sharing[i] = sharing[i - 1];
      knowing[i] = knowing[i - 1];
      if (i - forget > 0) {
        sharing[i] = modSub(sharing[i], discovered[i - forget]);
        knowing[i] = modSub(knowing[i], discovered[i - forget]);
      }
      if (i - delay > 0) { sharing[i] = modAdd(sharing[i], discovered[i - delay]); }
      discovered[i] = modAdd(discovered[i], sharing[i]);
      knowing[i] = modAdd(knowing[i], sharing[i]);
    }
    return knowing[n];
  }
};
