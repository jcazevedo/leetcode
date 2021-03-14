#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int N = nums.size();
    map<int, int> prev;
    int curr = 0, cnt = 0;
    for (int i = 0; i < N; ++i) {
      curr += nums[i];
      if (curr == k)
        cnt++;
      if (i > 0) {
        int target = curr - k;
        cnt += prev[target];
      }
      prev[curr]++;
    }
    return cnt;
  }
};
