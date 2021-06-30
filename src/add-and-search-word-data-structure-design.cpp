#include <string>
#include <vector>

using namespace std;

struct TrieNode {
  bool word_exists;
  vector<TrieNode *> next;

  TrieNode() {
    word_exists = false;
    next.assign(26, nullptr);
  }
};

class WordDictionary {
private:
  TrieNode *root;

  bool search_aux(TrieNode *curr, const string &word, int i) {
    if (curr == nullptr)
      return false;
    if (i == word.size())
      return curr->word_exists;
    if (word[i] == '.') {
      bool good = false;
      for (char ch = 'a'; ch <= 'z' && !good; ++ch) {
        int idx = ch - 'a';
        good = good || search_aux(curr->next[idx], word, i + 1);
      }
      return good;
    }
    return search_aux(curr->next[word[i] - 'a'], word, i + 1);
  }

public:
  WordDictionary() { root = new TrieNode(); }

  void addWord(string word) {
    TrieNode *curr = root;
    for (char ch : word) {
      int idx = ch - 'a';
      if (curr->next[idx] == nullptr)
        curr->next[idx] = new TrieNode();
      curr = curr->next[idx];
    }
    curr->word_exists = true;
  }

  bool search(string word) { return search_aux(root, word, 0); }
};
