// 2976. Minimum Cost to Convert String I
// https://leetcode.com/problems/minimum-cost-to-convert-string-i/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  long long minimumCost(
      string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    unordered_map<char, unordered_map<char, long long>> distance;
    for (char ch1 = 'a'; ch1 <= 'z'; ++ch1) {
      for (char ch2 = 'a'; ch2 <= 'z'; ++ch2) {
        if (ch1 == ch2) {
          distance[ch1][ch2] = 0L;
        } else {
          distance[ch1][ch2] = -1L;
        }
      }
    }
    int N = original.size();
    for (int i = 0; i < N; ++i) {
      char from = original[i];
      char to = changed[i];
      if (distance[from][to] == -1 || cost[i] < distance[from][to]) { distance[from][to] = cost[i]; }
    }
    for (char k = 'a'; k <= 'z'; ++k) {
      for (char i = 'a'; i <= 'z'; ++i) {
        if (distance[i][k] == -1) { continue; }
        for (char j = 'a'; j <= 'z'; ++j) {
          if (distance[k][j] == -1) { continue; }
          if (distance[i][j] == -1 || (distance[i][j] > distance[i][k] + distance[k][j])) {
            distance[i][j] = distance[i][k] + distance[k][j];
          }
        }
      }
    }
    long long ans = 0L;
    int M = source.size();
    for (int i = 0; i < M; ++i) {
      char from = source[i];
      char to = target[i];
      if (distance[from][to] == -1) { return -1; }
      ans += distance[from][to];
    }
    return ans;
  }
};
