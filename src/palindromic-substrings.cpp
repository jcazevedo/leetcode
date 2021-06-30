#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> dp_in;
  vector<vector<int>> dp_exactly;

  void go(int left, int right, const string &s) {
    if (left > right)
      return;
    if (dp_in[left][right] == -1) {
      if (left == right)
        dp_in[left][right] = dp_exactly[left][right] = 1;
      else {
        go(left, right - 1, s);
        go(left + 1, right, s);
        go(left + 1, right - 1, s);
        dp_in[left][right] = dp_exactly[left][right] = 0;
        dp_in[left][right] += dp_in[left][right - 1];
        dp_in[left][right] += dp_in[left + 1][right];
        if (left + 1 <= right - 1)
          dp_in[left][right] -= dp_in[left + 1][right - 1];
        if (s[left] == s[right]) {
          if (left + 1 <= right - 1) {
            dp_in[left][right] += dp_exactly[left + 1][right - 1];
            dp_exactly[left][right] += dp_exactly[left + 1][right - 1];
          } else {
            dp_in[left][right]++;
            dp_exactly[left][right]++;
          }
        }
      }
    }
  }

public:
  int countSubstrings(string s) {
    int N = s.size();
    dp_in.assign(N, vector<int>(N, -1));
    dp_exactly.assign(N, vector<int>(N, -1));
    go(0, N - 1, s);
    return dp_in[0][N - 1];
  }
};
