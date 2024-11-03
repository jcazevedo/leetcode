// 126. Word Ladder II
// https://leetcode.com/problems/word-ladder-ii/

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 private:
  bool canTransformTo(const string& from, const string& to) {
    int cnt = 0;
    int N = from.size();
    for (int i = 0; i < N; ++i) {
      if (from[i] != to[i]) { ++cnt; }
    }
    return cnt == 1;
  }

  void rebuild(vector<string>& curr,
               unordered_map<string, vector<string>>& prev,
               string& beginWord,
               string& endWord,
               vector<vector<string>>& ans) {
    curr.push_back(endWord);
    if (beginWord == endWord) {
      reverse(begin(curr), end(curr));
      ans.push_back(curr);
      reverse(begin(curr), end(curr));
    } else {
      for (string& nextWord : prev[endWord]) { rebuild(curr, prev, beginWord, nextWord, ans); }
    }
    curr.pop_back();
  }

 public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    if (find(begin(wordList), end(wordList), endWord) == wordList.end()) { return vector<vector<string>>(); }
    unordered_map<string, vector<string>> graph;
    for (const string& s1 : wordList) {
      if (canTransformTo(beginWord, s1)) { graph[beginWord].push_back(s1); }
      if (s1 == beginWord) { continue; }
      for (const string& s2 : wordList) {
        if (canTransformTo(s1, s2)) { graph[s1].push_back(s2); }
      }
    }
    queue<pair<string, int>> q;
    unordered_map<string, int> visited;
    q.push({beginWord, 1});
    visited[beginWord] = 0;
    unordered_map<string, vector<string>> prev;
    bool found = false;
    while (!q.empty()) {
      pair<string, int> curr = q.front();
      q.pop();
      string currWord = curr.first;
      int currLen = curr.second;
      for (const string& nextWord : graph[currWord]) {
        if (visited.find(nextWord) != visited.end() && visited[nextWord] < currLen + 1) { continue; }
        prev[nextWord].push_back(currWord);
        if (nextWord == endWord) { found = true; }
        if (!found && visited.find(nextWord) == visited.end()) { q.push({nextWord, currLen + 1}); }
        visited[nextWord] = currLen + 1;
      }
    }
    vector<vector<string>> ans;
    vector<string> curr;
    rebuild(curr, prev, beginWord, endWord, ans);
    return ans;
  }
};
