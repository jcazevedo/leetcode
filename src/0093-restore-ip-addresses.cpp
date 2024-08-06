// 93. Restore IP Addresses
// https://leetcode.com/problems/restore-ip-addresses/

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool validOctet(string s) {
    istringstream ss(s);
    int v;
    ss >> v;
    return s != "" && (s == "0" || (s[0] != '0' && v < 256));
  }

  void go(const string& s, int i, int r, vector<int>& dots, vector<string>& ans) {
    if (i == (int)s.size() && r != 3) { return; }
    if (r == 3) {
      if (validOctet(s.substr(dots[2]))) {
        string sol = "";
        for (int j = 0; j < 3; ++j) {
          if (j == 0) {
            sol += s.substr(0, dots[j]);
            sol += ".";
          } else {
            sol += s.substr(dots[j - 1], dots[j] - dots[j - 1]);
            sol += ".";
          }
        }
        sol += s.substr(dots[2]);
        ans.push_back(sol);
      }
      return;
    }
    bool good = false;
    if (r == 0) {
      good = validOctet(s.substr(0, i));
    } else {
      good = validOctet(s.substr(dots[r - 1], i - dots[r - 1]));
    }
    if (good) {
      dots[r] = i;
      go(s, i + 1, r + 1, dots, ans);
    }
    go(s, i + 1, r, dots, ans);
  }

 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<int> dots(3, -1);
    go(s, 1, 0, dots, ans);
    return ans;
  }
};
