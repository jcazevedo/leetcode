// 949. Largest Time for Given Digits
// https://leetcode.com/problems/largest-time-for-given-digits/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool good(const vector<int>& A) {
    int hours = A[0] * 10 + A[1];
    int minutes = A[2] * 10 + A[3];
    return hours <= 23 && minutes <= 59;
  }

public:
  string largestTimeFromDigits(vector<int>& A) {
    sort(A.begin(), A.end());
    vector<int> best;
    do {
      if (good(A))
        best = A;
    } while (next_permutation(A.begin(), A.end()));
    if (best.empty())
      return "";
    string ans = "";
    ans += best[0] + '0';
    ans += best[1] + '0';
    ans += ':';
    ans += best[2] + '0';
    ans += best[3] + '0';
    return ans;
  }
};
