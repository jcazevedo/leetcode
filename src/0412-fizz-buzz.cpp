// 412. Fizz Buzz
// https://leetcode.com/problems/fizz-buzz/

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  string toString(int n) {
    ostringstream ss;
    ss << n;
    return ss.str();
  }

public:
  vector<string> fizzBuzz(int n) {
    vector<string> ans;
    for (int i = 1; i <= n; ++i)
      if (i % 3 == 0 && i % 5 == 0)
        ans.push_back("FizzBuzz");
      else if (i % 3 == 0)
        ans.push_back("Fizz");
      else if (i % 5 == 0)
        ans.push_back("Buzz");
      else
        ans.push_back(toString(i));
    return ans;
  }
};
