// 2409. Count Days Spent Together
// https://leetcode.com/problems/count-days-spent-together/

#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  static vector<int> md;

  int month(const string& date) { return (date[0] - '0') * 10 + (date[1] - '0'); }

  int day(const string& date) { return (date[3] - '0') * 10 + (date[4] - '0'); }

 public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    int maa = month(arriveAlice);
    int daa = day(arriveAlice);
    int mla = month(leaveAlice);
    int dla = day(leaveAlice);
    int mab = month(arriveBob);
    int dab = day(arriveBob);
    int mlb = month(leaveBob);
    int dlb = day(leaveBob);
    int ans = 0;
    int months = md.size();
    bool alice = false, bob = false;
    for (int m = 1; m <= months; ++m) {
      for (int d = 1; d <= md[m - 1]; ++d) {
        if (m == maa && d == daa) { alice = true; }
        if (m == mab && d == dab) { bob = true; }
        if (alice && bob) { ++ans; }
        if (m == mla && d == dla) { alice = false; }
        if (m == mlb && d == dlb) { bob = false; }
      }
    }
    return ans;
  }
};

vector<int> Solution::md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
