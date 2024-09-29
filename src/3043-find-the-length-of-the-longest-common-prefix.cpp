// 3043. Find the Length of the Longest Common Prefix
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

#include <algorithm>
#include <vector>

using namespace std;

class TrieNode {
 public:
  vector<TrieNode*> next;

  TrieNode() { next.assign(10, nullptr); }
};

void insert(TrieNode* root, const vector<int>& seq) {
  TrieNode* curr = root;
  for (int num : seq) {
    if (curr->next[num] == nullptr) { curr->next[num] = new TrieNode(); }
    curr = curr->next[num];
  }
}

int maxPrefix(TrieNode* root, const vector<int>& seq) {
  TrieNode* curr = root;
  int ans = 0;
  for (int num : seq) {
    if (curr->next[num] == nullptr) { break; }
    curr = curr->next[num];
    ++ans;
  }
  return ans;
}

class Solution {
 private:
  vector<int> toSeq(int num) {
    vector<int> ans;
    while (num) {
      ans.push_back(num % 10);
      num /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

 public:
  int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    TrieNode* trie = new TrieNode();
    for (int v : arr1) {
      vector<int> seq = toSeq(v);
      insert(trie, seq);
    }
    int ans = 0;
    for (int v : arr2) {
      vector<int> seq = toSeq(v);
      ans = max(ans, maxPrefix(trie, seq));
    }
    return ans;
  }
};
