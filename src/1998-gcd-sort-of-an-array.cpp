// 1998. GCD Sort of an Array
// https://leetcode.com/problems/gcd-sort-of-an-array/

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

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
  vector<int> sieve(int n) {
    vector<int> ans(n);
    for (int i = 2; i < n; ++i) { ans[i] = i; }
    for (int i = 2; i * i < n; ++i) {
      if (ans[i] != i) { continue; }
      for (int j = i * i; j < n; j += i) {
        if (ans[j] > i) { ans[j] = i; }
      }
    }
    return ans;
  }

  vector<int> primeFactors(int n, vector<int>& pf) {
    vector<int> ans;
    while (n > 1) {
      ans.push_back(pf[n]);
      n /= pf[n];
    }
    return ans;
  }

 public:
  bool gcdSort(vector<int>& nums) {
    int n = nums.size();
    int hi = numeric_limits<int>::min();
    for (int num : nums) { hi = max(hi, num); }
    vector<int> pf = sieve(hi + 1);
    UnionFind uf(hi + 1);
    for (int num : nums) {
      for (int fact : primeFactors(num, pf)) { uf.unionSet(num, fact); }
    }
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i) {
      if (!uf.connectedSet(nums[i], sorted[i])) { return false; }
    }
    return true;
  }
};
