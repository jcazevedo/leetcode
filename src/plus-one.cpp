#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> res;
    int i = digits.size() - 1, c = 1;
    while (i >= 0) {
      int n = digits[i--] + c;
      res.push_back(n % 10);
      c = n / 10;
    }
    if (c)
      res.push_back(c);
    reverse(res.begin(), res.end());
    return res;
  }
};
