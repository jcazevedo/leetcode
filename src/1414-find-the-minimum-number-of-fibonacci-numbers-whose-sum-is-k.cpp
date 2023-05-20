// 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

#include <vector>

using namespace std;

class Solution {
public:
  int findMinFibonacciNumbers(int k) {
    vector<long long> fib = {1, 1};
    while (fib.back() < k)
      fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    int cnt = 0;
    while (k > 0) {
      int idx = lower_bound(fib.begin(), fib.end(), k) - fib.begin();
      if (fib[idx] > k)
        idx--;
      k -= fib[idx];
      cnt++;
    }
    return cnt;
  }
};
