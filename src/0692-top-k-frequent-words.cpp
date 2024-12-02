// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freq;
    for (const string& word : words) { ++freq[word]; }
    int N = words.size();
    vector<priority_queue<string, vector<string>, greater<string>>> buckets(N + 1);
    for (pair<string, int> kv : freq) { buckets[kv.second].push(kv.first); }
    vector<string> ans(k);
    int i = 0;
    for (int f = N; f >= 1 && i < k; --f) {
      while (!buckets[f].empty() && i < k) {
        ans[i++] = buckets[f].top();
        buckets[f].pop();
      }
    }
    return ans;
  }
};
