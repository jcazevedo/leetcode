// 3525. Find X Value of Array II
// https://leetcode.com/problems/find-x-value-of-array-ii/

#include <vector>

using namespace std;

struct Node {
  int product = 1;
  int count[5] = {};
};

class SegmentTree {
 public:
  SegmentTree(const vector<int>& nums, int _k) : n(nums.size()), k(_k), tree(4 * nums.size()) {
    build(nums, 1, 0, nums.size() - 1);
  }

  void update(int index, int value) { update(1, 0, n - 1, index, value % k); }

  Node query(int left, int right) { return query(1, 0, n - 1, left, right); }

 private:
  int n;
  int k;
  vector<Node> tree;

  Node merge(const Node& left, const Node& right) const {
    Node result;
    result.product = left.product * right.product % k;
    for (int remainder = 0; remainder < k; ++remainder) { result.count[remainder] = left.count[remainder]; }
    for (int remainder = 0; remainder < k; ++remainder) {
      result.count[(left.product * remainder) % k] += right.count[remainder];
    }
    return result;
  }

  void build(const vector<int>& nums, int node, int left, int right) {
    if (left == right) {
      int remainder = nums[left] % k;
      tree[node].product = remainder;
      tree[node].count[remainder] = 1;
      return;
    }
    int middle = left + (right - left) / 2;
    build(nums, node * 2, left, middle);
    build(nums, node * 2 + 1, middle + 1, right);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  void update(int node, int left, int right, int index, int value) {
    if (left == right) {
      tree[node] = Node();
      tree[node].product = value;
      tree[node].count[value] = 1;
      return;
    }
    int middle = left + (right - left) / 2;
    if (index <= middle) {
      update(node * 2, left, middle, index, value);
    } else {
      update(node * 2 + 1, middle + 1, right, index, value);
    }
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  Node query(int node, int left, int right, int query_left, int query_right) const {
    if (query_left <= left && right <= query_right) { return tree[node]; }
    int middle = left + (right - left) / 2;
    if (query_right <= middle) { return query(node * 2, left, middle, query_left, query_right); }
    if (query_left > middle) { return query(node * 2 + 1, middle + 1, right, query_left, query_right); }
    return merge(query(node * 2, left, middle, query_left, query_right),
                 query(node * 2 + 1, middle + 1, right, query_left, query_right));
  }
};

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
    SegmentTree tree(nums, k);
    int n = queries.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      tree.update(queries[i][0], queries[i][1]);
      ans[i] = tree.query(queries[i][2], nums.size() - 1).count[queries[i][3]];
    }
    return ans;
  }
};
