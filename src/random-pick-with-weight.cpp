#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> values;

public:
  Solution(vector<int>& w) {
    srand(time(NULL));
    int N = w.size();
    values.assign(N, 0);
    values[0] = w[0];
    for (int i = 1; i < N; ++i) {
      values[i] = w[i];
      values[i] += values[i - 1];
    }
  }

  int pickIndex() { return upper_bound(values.begin(), values.end(), rand() % values.back()) - values.begin(); }
};
