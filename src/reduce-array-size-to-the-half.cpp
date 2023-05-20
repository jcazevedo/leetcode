#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int minSetSize(vector<int>& arr) {
    map<int, int> cnt;
    for (int v : arr) {
      cnt[v]++;
    }
    int N = arr.size();
    vector<int> tot;
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
      tot.push_back(itr->second);
    }
    sort(tot.begin(), tot.end());
    reverse(tot.begin(), tot.end());
    int curr = tot[0];
    int ans = 1;
    while (curr < N / 2) {
      curr += tot[ans];
      ans++;
    }
    return ans;
  }
};
