// 38. Count and Say
// https://leetcode.com/problems/count-and-say/

#include <sstream>
#include <string>

using namespace std;

class Solution {
private:
  string intToString(int v) {
    ostringstream ss;
    ss << v;
    return ss.str();
  }

public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    string prev = countAndSay(n - 1);
    int N = prev.size();
    string ans = "";
    int count = 1;
    for (int i = 1; i < N; ++i) {
      if (prev[i] == prev[i - 1]) {
        count++;
      } else {
        ans += intToString(count);
        ans += prev[i - 1];
        count = 1;
      }
    }
    ans += intToString(count);
    ans += prev[N - 1];
    return ans;
  }
};
