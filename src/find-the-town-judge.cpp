#include <vector>

using namespace std;

class Solution {
public:
  int findJudge(int N, vector<vector<int>> &trust) {
    vector<int> in_degree(N + 1, 0);
    vector<int> out_degree(N + 1, 0);
    int L = trust.size();
    for (int i = 0; i < L; ++i) {
      out_degree[trust[i][0]]++;
      in_degree[trust[i][1]]++;
    }
    for (int i = 1; i <= N; ++i) {
      if (out_degree[i] == 0 && in_degree[i] == N - 1)
        return i;
    }
    return -1;
  }
};
