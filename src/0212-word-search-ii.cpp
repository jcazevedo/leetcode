// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/

#include <set>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
  bool is_end;
  vector<TrieNode*> next;

  TrieNode() {
    is_end = false;
    next.assign(26, nullptr);
  }
};

class Solution {
private:
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void insert(TrieNode* node, string word) {
    TrieNode* curr = node;
    for (char ch : word) {
      if (curr->next[ch - 'a'] == nullptr) {
        curr->next[ch - 'a'] = new TrieNode();
      }
      curr = curr->next[ch - 'a'];
    }
    curr->is_end = true;
  }

  set<string> found;

  void dfs(vector<vector<char>>& board, TrieNode* trie, vector<vector<bool>>& visited, int i, int j, string word) {
    if (trie->next[board[i][j] - 'a'] != nullptr) {
      TrieNode* next = trie->next[board[i][j] - 'a'];
      word += board[i][j];
      if (next->is_end)
        found.insert(word);
      visited[i][j] = true;
      for (pair<int, int> dir : dirs) {
        int ni = i + dir.first;
        int nj = j + dir.second;
        if (ni >= 0 && ni < (int)board.size() && nj >= 0 && nj < (int)board[ni].size() && !visited[ni][nj]) {
          dfs(board, next, visited, ni, nj, word);
        }
      }
      word.pop_back();
      visited[i][j] = false;
    }
    if (word.empty()) {
      int nj = j + 1;
      int ni = i;
      if (nj >= (int)board[ni].size()) {
        ni = i + 1;
        nj = 0;
      }
      if (ni < (int)board.size()) {
        dfs(board, trie, visited, ni, nj, word);
      }
    }
  }

public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* trie = new TrieNode();
    for (string word : words)
      insert(trie, word);
    int H = board.size();
    int W = board[0].size();
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    found.clear();
    dfs(board, trie, visited, 0, 0, "");
    vector<string> res;
    for (string word : found)
      res.push_back(word);
    return res;
  }
};
