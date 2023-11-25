// 1429. First Unique Number
// https://leetcode.com/problems/first-unique-number/

#include <queue>
#include <unordered_map>

using namespace std;

class FirstUnique {
 private:
  unordered_map<int, int> cnt;
  queue<int> q;

 public:
  FirstUnique(vector<int>& nums) {
    for (int num : nums) add(num);
  }

  int showFirstUnique() {
    while (!q.empty() && cnt[q.front()] > 1) q.pop();
    if (q.empty()) return -1;
    return q.front();
  }

  void add(int value) {
    if (cnt[value] == 0) q.push(value);
    cnt[value]++;
  }
};
