// 2140. Solving Questions With Brainpower
// https://leetcode.com/problems/solving-questions-with-brainpower/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 private:
  long long best(int i, vector<long long>& cache, int n, const vector<vector<int>>& questions) {
    if (i >= n) { return 0; }
    if (cache[i] != -1) { return cache[i]; }
    long long ans =
        max(questions[i][0] + best(i + questions[i][1] + 1, cache, n, questions), best(i + 1, cache, n, questions));
    cache[i] = ans;
    return ans;
  };

 public:
  long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> cache(n, -1);
    return best(0, cache, n, questions);
  }
};
