#include <vector>

using namespace std;

class Solution {
private:
  vector<int> ans;

  void gen(int curr, int low, int high) {
    if (curr >= low)
      ans.push_back(curr);
    if (curr % 10 != 9) {
      int next_value = curr * 10 + (curr % 10 + 1);
      if (next_value <= high)
        gen(next_value, low, high);
    }
  }

public:
  vector<int> sequentialDigits(int low, int high) {
    ans.clear();
    for (int i = 1; i <= 9; ++i)
      gen(i, low, high);
    sort(ans.begin(), ans.end());
    return ans;
  }
};
