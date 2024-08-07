// 273. Integer to English Words
// https://leetcode.com/problems/integer-to-english-words/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  static const vector<string> to10;
  static const vector<string> to20;
  static const vector<string> to100;

  string toWords(int num) {
    if (num < 10) { return to10[num]; }
    if (num < 20) { return to20[num - 10]; }
    if (num < 100) { return to100[num / 10] + (num % 10 ? " " + toWords(num % 10) : ""); }
    if (num < 1000) { return toWords(num / 100) + " Hundred" + (num % 100 ? " " + toWords(num % 100) : ""); }
    if (num < 1000000) { return toWords(num / 1000) + " Thousand" + (num % 1000 ? " " + toWords(num % 1000) : ""); }
    if (num < 1000000000) {
      return toWords(num / 1000000) + " Million" + (num % 1000000 ? " " + toWords(num % 1000000) : "");
    }
    return toWords(num / 1000000000) + " Billion" + (num % 1000000000 ? " " + toWords(num % 1000000000) : "");
  }

 public:
  string numberToWords(int num) {
    if (num == 0) { return "Zero"; }
    return toWords(num);
  }
};

const vector<string> Solution::to10 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
const vector<string> Solution::to20 = {"Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                                       "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const vector<string> Solution::to100 = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
                                        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
