#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;
    unordered_map<char, int> last;
    int N = S.size();
    for (int i = 0; i < N; ++i) last[S[i]] = i;
    int curr = 0;
    int prev = -1;
    for (int i = 0; i < N; ++i) {
      curr = max(curr, last[S[i]]);
      if (curr == i) {
        ans.push_back(curr - prev);
        prev = curr;
      }
    }
    return ans;
  }
};
