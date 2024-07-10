// 1598. Crawler Log Folder
// https://leetcode.com/problems/crawler-log-folder/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int ans = 0;
    for (const string& log : logs)
      if (log == "../")
        ans = max(ans - 1, 0);
      else if (log != "./")
        ans += 1;
    return ans;
  }
};
