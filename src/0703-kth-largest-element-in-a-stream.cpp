// 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <queue>
#include <vector>

using namespace std;

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  int N;

public:
  KthLargest(int k, vector<int>& nums) {
    N = k;
    for (const int& num : nums)
      pq.push(num);
  }

  int add(int val) {
    pq.push(val);
    while ((int)pq.size() > N)
      pq.pop();
    return pq.top();
  }
};
