#include <vector>

using namespace std;

class TrieNode {
public:
  vector<TrieNode*> next;

  TrieNode() { next.assign(2, nullptr); }
};

void insert(TrieNode* root, int num) {
  TrieNode* curr = root;
  for (int i = 30; i >= 0; --i) {
    int idx = 0;
    if (num & (1 << i))
      idx = 1;
    if (curr->next[idx] == nullptr)
      curr->next[idx] = new TrieNode();
    curr = curr->next[idx];
  }
}

class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int ans = 0;
    TrieNode* trie = new TrieNode();
    for (int num : nums) {
      insert(trie, num);
      int xor_value = 0;
      TrieNode* curr = trie;
      for (int i = 30; i >= 0; --i) {
        int idx = 0;
        if (num & (1 << i))
          idx = 1;
        xor_value <<= 1;
        if (curr->next[idx ^ 1] != nullptr) {
          curr = curr->next[idx ^ 1];
          xor_value += 1;
        } else {
          curr = curr->next[idx];
        }
      }
      ans = max(ans, xor_value);
    }
    return ans;
  }
};
