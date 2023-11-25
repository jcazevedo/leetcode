// 179. Largest Number
// https://leetcode.com/problems/largest-number/

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  string int_to_string(int v) {
    ostringstream ss;
    ss << v;
    return ss.str();
  }

public:
  string largestNumber(vector<int>& nums) {
    vector<string> numbers;
    bool all_zero = true;
    for (int num : nums) {
      if (num != 0)
        all_zero = false;
      numbers.push_back(int_to_string(num));
    }
    if (all_zero)
      return "0";
    sort(numbers.begin(), numbers.end(),
         [](const string& s1, const string& s2) {
           return (s1 + s2) >= (s2 + s1);
         });
    string ans = "";
    for (string number : numbers)
      ans += number;
    return ans;
  }
};
