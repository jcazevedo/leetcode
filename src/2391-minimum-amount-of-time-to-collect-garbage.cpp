// 2391. Minimum Amount of Time to Collect Garbage
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int N = garbage.size();
    vector<unordered_map<char, int>> garbageCount = vector<unordered_map<char, int>>(N, unordered_map<char, int>());
    vector<char> garbageTypes = {'P', 'G', 'M'};
    unordered_map<char, int> finalHouse;
    for (char garbageType : garbageTypes)
      finalHouse[garbageType] = -1;
    for (int i = 0; i < N; ++i)
      for (char ch : garbage[i]) {
        garbageCount[i][ch]++;
        finalHouse[ch] = i;
      }

    int ans = 0;
    for (char garbageType : garbageTypes)
      for (int i = 0; i <= finalHouse[garbageType]; ++i) {
        ans += garbageCount[i][garbageType];
        if (i + 1 <= finalHouse[garbageType])
          ans += travel[i];
      }
    return ans;
  }
};
