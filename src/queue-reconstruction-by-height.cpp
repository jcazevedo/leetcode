#include <vector>

using namespace std;

class Solution {
private:
  static bool compare(const vector<int>& p1, const vector<int>& p2) {
    if (p1[0] != p2[0])
      return p1[0] > p2[0];
    return p1[1] < p2[1];
  }

public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), compare);
    vector<vector<int>> res;
    for (vector<int> p : people) {
      res.insert(res.begin() + p[1], p);
    }
    return res;
  }
};
