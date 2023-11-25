// 2551. Put Marbles in Bags
// https://leetcode.com/problems/put-marbles-in-bags/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  long long putMarbles(vector<int>& weights, int k) {
    int N = weights.size();
    vector<long long> splits;
    for (int i = 0; i < N - 1; ++i)
      splits.push_back(weights[i] + weights[i + 1]);
    sort(splits.begin(), splits.end());
    long long maxV, minV;
    maxV = minV = weights[0] + weights[N - 1];
    for (int i = 0; i < k - 1; ++i) {
      minV += splits[i];
      maxV += splits[N - 2 - i];
    }
    return maxV - minV;
  }
};
