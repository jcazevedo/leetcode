#include <vector>

using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    sort(citations.begin(), citations.end());
    int ans = citations.size();
    for (int cit : citations) {
      if (cit >= ans)
        return ans;
      ans--;
    }
    return ans;
  }
};
