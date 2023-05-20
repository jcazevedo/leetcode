// 1108. Defanging an IP Address
// https://leetcode.com/problems/defanging-an-ip-address/

#include <string>

using namespace std;

class Solution {
public:
  string defangIPaddr(string address) {
    string res = "";
    for (char ch : address) {
      if (ch == '.')
        res += "[.]";
      else
        res += ch;
    }
    return res;
  }
};
