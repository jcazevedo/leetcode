#include <vector>

using namespace std;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int ans = 0;
    int N = arr.size();
    for (int i = 1; i < N && arr[i] > arr[i - 1]; ++i) ans = i;
    return ans;
  }
};
