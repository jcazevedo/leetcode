// 1233. Remove Sub-Folders from the Filesystem
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
  bool folderExists;
  unordered_map<string, TrieNode*> next;

  TrieNode() { folderExists = false; }
};

void addFolders(TrieNode* root, const vector<string>& folder) {
  TrieNode* curr = root;
  for (const string& f : folder) {
    if (curr->next[f] == nullptr) { curr->next[f] = new TrieNode(); }
    curr = curr->next[f];
  }
  curr->folderExists = true;
}

void collectFolders(TrieNode* node, vector<string>& words, vector<string>& curr) {
  if (node->folderExists) {
    string toAdd = "";
    for (const string& s : curr) { toAdd += "/" + s; }
    words.push_back(toAdd);
  } else {
    for (unordered_map<string, TrieNode*>::iterator itr = node->next.begin(); itr != node->next.end(); ++itr) {
      curr.push_back(itr->first);
      collectFolders(itr->second, words, curr);
      curr.pop_back();
    }
  }
}

vector<string> split(const string& folder) {
  vector<string> ans;
  int N = folder.size();
  string curr = "";
  for (int i = 1; i < N; ++i) {
    if (folder[i] == '/') {
      ans.push_back(curr);
      curr = "";
    } else {
      curr += folder[i];
    }
  }
  ans.push_back(curr);
  return ans;
}

class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    TrieNode* root = new TrieNode();
    for (const string& f : folder) {
      vector<string> s = split(f);
      addFolders(root, s);
    }
    vector<string> ans;
    vector<string> curr;
    collectFolders(root, ans, curr);
    return ans;
  }
};
