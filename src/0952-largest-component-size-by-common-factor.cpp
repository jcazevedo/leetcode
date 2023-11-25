// 952. Largest Component Size by Common Factor
// https://leetcode.com/problems/largest-component-size-by-common-factor/

#include <cmath>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

#define MAXN 100000

class UnionFind {
 private:
  vector<int> p, rank;

 public:
  UnionFind(int N) {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool connectedSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!connectedSet(i, j)) {
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

class Solution {
 private:
  set<int> factors(int n) {
    set<int> ans;
    for (int i = 1; i <= sqrt(n); ++i)
      if (n % i == 0) {
        ans.insert(i);
        ans.insert(n / i);
      }
    return ans;
  }

 public:
  int largestComponentSize(vector<int>& nums) {
    unordered_map<int, vector<int>> byFactor;
    set<int> totalFactors;
    UnionFind uf = UnionFind(MAXN + 1);
    for (int num : nums) {
      set<int> facts = factors(num);
      for (int fact : facts) {
        if (fact == 1) continue;
        byFactor[fact].push_back(num);
      }
    }
    for (auto itr = byFactor.begin(); itr != byFactor.end(); ++itr) {
      vector<int> nums = itr->second;
      int u = nums[0];
      for (int i = 1; i < (int)nums.size(); ++i) uf.unionSet(u, nums[i]);
    }
    unordered_map<int, int> groupSize;
    for (int num : nums) groupSize[uf.findSet(num)]++;
    int ans = 0;
    for (auto itr = groupSize.begin(); itr != groupSize.end(); ++itr)
      ans = max(ans, itr->second);
    return ans;
  }
};
