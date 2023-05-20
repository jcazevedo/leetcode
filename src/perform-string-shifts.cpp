#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string stringShift(string s, vector<vector<int>>& shift) {
    int N = s.size(), V = shift.size();

    int diff = 0;
    for (int i = 0; i < V; ++i)
      diff += shift[i][0] == 0 ? shift[i][1] : -shift[i][1];

    if (diff > 0) {
      diff %= N;
      return s.substr(diff) + s.substr(0, diff);
    } else {
      diff = (-diff) % N;
      return s.substr(N - diff) + s.substr(0, N - diff);
    }
  }
};
