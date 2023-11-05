// 1535. Find the Winner of an Array Game
// https://leetcode.com/problems/find-the-winner-of-an-array-game/

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int getWinner(vector<int>& arr, int k) {
    int N = arr.size();
    unordered_map<int, int> wins;
    int curr = arr[0];
    for (int i = 1; i < N; ++i) {
      curr = max(curr, arr[i]);
      wins[curr]++;
      if (wins[curr] == k)
        return curr;
    }
    return curr;
  }
};
