// 2416. Sum of Prefix Scores of Strings
// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
  int count;
  unordered_map<char, TrieNode*> next;

  TrieNode() { count = 0; }
};

void insertTrie(TrieNode* node, const string& word) {
  TrieNode* curr = node;
  for (char ch : word) {
    if (curr->next[ch] == nullptr) { curr->next[ch] = new TrieNode(); }
    curr = curr->next[ch];
    curr->count++;
  }
}

int prefixCount(TrieNode* node, const string& word) {
  TrieNode* curr = node;
  int ans = 0;
  for (char ch : word) {
    if (curr->next[ch] == nullptr) { break; }
    curr = curr->next[ch];
    ans += curr->count;
  }
  return ans;
}

class Solution {
 public:
  vector<int> sumPrefixScores(vector<string>& words) {
    TrieNode* trie = new TrieNode();
    for (const string& word : words) { insertTrie(trie, word); }
    int N = words.size();
    vector<int> ans(N);
    for (int i = 0; i < N; ++i) { ans[i] = prefixCount(trie, words[i]); }
    return ans;
  }
};
