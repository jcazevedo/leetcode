// 1426. Counting Elements
// https://leetcode.com/problems/counting-elements/

#include <vector>

using namespace std;

#define MAXN 1010

class Solution {
private:
  bool exists[MAXN];

public:
  int countElements(vector<int>& arr) {
    int N = arr.size();
    for (int i = 0; i < N; ++i) {
      exists[arr[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
      if (exists[arr[i] + 1]) {
        cnt++;
      }
    }
    return cnt;
  }
};
