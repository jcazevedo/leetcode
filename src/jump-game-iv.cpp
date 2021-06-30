#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minJumps(vector<int> &arr) {
    unordered_map<int, vector<int>> idxs;
    unordered_map<int, bool> visited;
    int N = arr.size();
    for (int i = 0; i < N; ++i)
      idxs[arr[i]].push_back(i);
    vector<int> dist(N, INT_MAX);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      if (i - 1 >= 0 && dist[i] + 1 < dist[i - 1]) {
        dist[i - 1] = dist[i] + 1;
        q.push(i - 1);
      }
      if (i + 1 < N && dist[i] + 1 < dist[i + 1]) {
        dist[i + 1] = dist[i] + 1;
        q.push(i + 1);
      }
      if (!visited[arr[i]]) {
        visited[arr[i]] = true;
        for (int j : idxs[arr[i]]) {
          if (dist[i] + 1 < dist[j]) {
            dist[j] = dist[i] + 1;
            q.push(j);
          }
        }
      }
    }
    return dist[N - 1];
  }
};
