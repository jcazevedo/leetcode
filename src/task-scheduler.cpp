#include <vector>

using namespace std;

class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> cnts = vector<int>(26, 0);
    for (char task : tasks)
      cnts[task - 'A']++;
    sort(cnts.begin(), cnts.end());
    int max_cnt = cnts[25] - 1;
    int spaces = max_cnt * n;
    for (int i = 24; i >= 0; --i)
      spaces -= min(max_cnt, cnts[i]);
    spaces = max(spaces, 0);
    return tasks.size() + spaces;
  }
};
