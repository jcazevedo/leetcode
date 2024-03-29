// 1299. Replace Elements with Greatest Element on Right Side
// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int N = arr.size();
    int largest = -1;
    for (int i = N - 1; i >= 0; --i) {
      int next_largest = max(arr[i], largest);
      arr[i] = largest;
      largest = next_largest;
    }
    return arr;
  }
};
