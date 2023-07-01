// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
  unordered_map<int, string> digits = {{1, "IVX"}, {2, "XLC"}, {3, "CDM"}, {4, "M  "}};

public:
  string intToRoman(int num) {
    string ans = "";
    int pow = 1;
    while (num) {
      int digit = num % 10;
      char one = digits[pow][0];
      char five = digits[pow][1];
      char next = digits[pow][2];
      string curr = "";
      if (digit == 9) {
        curr += one;
        curr += next;
      } else if (digit >= 5) {
        curr += five;
        digit -= 5;
        while (digit) {
          curr += one;
          --digit;
        }
      } else if (digit == 4) {
        curr += one;
        curr += five;
      } else {
        while (digit) {
          curr += one;
          --digit;
        }
      }
      num /= 10;
      ++pow;
      ans = curr + ans;
    }
    return ans;
  }
};
