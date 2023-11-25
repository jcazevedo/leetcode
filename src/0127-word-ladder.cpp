// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/

#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  bool is_connected(string& a, string& b) {
    int N = a.size(), cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (a[i] != b[i]) cnt++;
      if (cnt > 1) return false;
    }
    return true;
  }

 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int N = wordList.size();
    vector<vector<int>> graph(N + 1, vector<int>());
    int target = -1;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (is_connected(wordList[i], wordList[j])) {
          graph[i + 1].push_back(j + 1);
          graph[j + 1].push_back(i + 1);
        }
      }
      if (is_connected(beginWord, wordList[i])) graph[0].push_back(i + 1);
      if (wordList[i] == endWord) target = i + 1;
    }
    if (target == -1) return 0;
    vector<int> dist(N + 1, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 1;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      int d = dist[curr];
      for (int next : graph[curr]) {
        if (dist[next] == -1) {
          if (next == target) return d + 1;
          dist[next] = d + 1;
          q.push(next);
        }
      }
    }
    return 0;
  }
};
