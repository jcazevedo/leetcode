// 3727. Maximum Alternating Sum of Squares
// https://leetcode.com/problems/maximum-alternating-sum-of-squares/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    priority_queue<long long> pq;
    for (int num : nums) { pq.push((long long)num * num); }
    int visited = 0;
    int positive = (n + 1) / 2;
    long long answer = 0L;
    while (!pq.empty()) {
      long long curr = pq.top();
      if (visited < positive) {
        answer += curr;
      } else {
        answer -= curr;
      }
      pq.pop();
      ++visited;
    }
    return answer;
  }
};
