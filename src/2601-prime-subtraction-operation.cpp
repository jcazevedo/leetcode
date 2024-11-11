// 2601. Prime Subtraction Operation
// https://leetcode.com/problems/prime-subtraction-operation/

#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  bool primeSubOperation(vector<int>& nums) {
    vector<bool> isPrime(1001, true);
    for (int p = 2; p * p < 1001; ++p) {
      if (isPrime[p]) {
        for (int i = p * p; i < 1001; i += p) { isPrime[i] = false; }
      }
    }
    vector<int> primes;
    for (int i = 2; i < 1001; ++i) {
      if (isPrime[i]) { primes.push_back(i); }
    }
    int N = nums.size(), P = primes.size(), prev = numeric_limits<int>::min();
    for (int i = 0; i < N; ++i) {
      bool found = false;
      for (int p = P - 1; p >= 0 && !found; --p) {
        if (primes[p] < nums[i] && nums[i] - primes[p] > prev) {
          nums[i] -= primes[p];
          found = true;
        }
      }
      if (!found && nums[i] <= prev) { return false; }
      prev = nums[i];
    }
    return true;
  }
};
