// 1601. Maximum Number of Achievable Transfer Requests
// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int maxRequests(int curr, vector<int>& buildingDiff,
                  vector<vector<int>>& requests, int count, int bestSoFar) {
    if (curr == (int)requests.size()) {
      for (int d : buildingDiff)
        if (d != 0)
          return -1;
      return max(count, bestSoFar);
    }

    if ((int)requests.size() - curr + count > bestSoFar) {
      --buildingDiff[requests[curr][0]];
      ++buildingDiff[requests[curr][1]];
      bestSoFar = max(bestSoFar, maxRequests(curr + 1, buildingDiff, requests,
                                             count + 1, bestSoFar));
      ++buildingDiff[requests[curr][0]];
      --buildingDiff[requests[curr][1]];
    }

    if ((int)requests.size() - curr + count > bestSoFar) {
      bestSoFar = max(bestSoFar, maxRequests(curr + 1, buildingDiff, requests,
                                             count, bestSoFar));
    }

    return bestSoFar;
  }

public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    vector<int> buildingDiff = vector<int>(n, 0);
    return maxRequests(0, buildingDiff, requests, 0, 0);
  }
};
