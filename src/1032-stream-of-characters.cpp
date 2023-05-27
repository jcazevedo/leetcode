// 1032. Stream of Characters
// https://leetcode.com/problems/stream-of-characters/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define MAXL 200

struct TrieNode {
  bool hasWord;
  unordered_map<char, TrieNode*> next;

  TrieNode() : hasWord(false) {}
};

class Trie {
private:
  TrieNode* root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* curr = root;
    for (char ch : word) {
      if (curr->next.find(ch) == curr->next.end())
        curr->next[ch] = new TrieNode();
      curr = curr->next[ch];
    }
    curr->hasWord = true;
  }

  bool hasPrefix(string word) {
    TrieNode* curr = root;
    if (curr->hasWord)
      return true;
    for (char ch : word) {
      if (curr->next.find(ch) == curr->next.end())
        return false;
      curr = curr->next[ch];
      if (curr->hasWord)
        return true;
    }
    return false;
  }
};

class StreamChecker {
private:
  Trie* trie;
  string current;

public:
  StreamChecker(vector<string>& words) : current("") {
    trie = new Trie();
    for (string word : words) {
      reverse(word.begin(), word.end());
      trie->insert(word);
    }
  }

  bool query(char letter) {
    current = letter + current;
    if (current.size() > MAXL)
      current = current.substr(0, MAXL);
    return trie->hasPrefix(current);
  }
};
