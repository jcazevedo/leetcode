#include <string>
#include <vector>

using namespace std;

struct TrieNode {
  bool is_end;
  vector<TrieNode *> next;

  TrieNode() {
    is_end = false;
    next.assign(26, nullptr);
  }
};

class Trie {
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *curr = root;
    for (char ch : word) {
      if (curr->next[ch - 'a'] == nullptr) {
        curr->next[ch - 'a'] = new TrieNode();
      }
      curr = curr->next[ch - 'a'];
    }
    curr->is_end = true;
  }

  bool search(string word) {
    TrieNode *curr = root;
    for (char ch : word) {
      if (curr->next[ch - 'a'] == nullptr)
        return false;
      curr = curr->next[ch - 'a'];
    }
    return curr->is_end;
  }

  bool startsWith(string prefix) {
    TrieNode *curr = root;
    for (char ch : prefix) {
      if (curr->next[ch - 'a'] == nullptr)
        return false;
      curr = curr->next[ch - 'a'];
    }
    return true;
  }
};
