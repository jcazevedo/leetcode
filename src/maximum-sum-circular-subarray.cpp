#include <vector>

using namespace std;

class Solution {
  int kadane(vector<int> &A) {
    int max_so_far = INT_MIN, max_ending_here = 0, N = A.size();
    for (int i = 0; i < N; ++i) {
      max_ending_here += A[i];
      max_so_far = max(max_so_far, max_ending_here);
      max_ending_here = max(max_ending_here, 0);
    }
    return max_so_far;
  }

public:
  int maxSubarraySumCircular(vector<int> &A) {
    bool all_negative = true;
    int max_value = INT_MIN;
    int N = A.size();
    for (int i = 0; i < N; ++i) {
      if (A[i] >= 0) {
        all_negative = false;
        break;
      }
      max_value = max(max_value, A[i]);
    }
    if (all_negative)
      return max_value;
    int max_kadane = kadane(A);
    int max_wrap = 0;
    for (int i = 0; i < N; ++i) {
      max_wrap += A[i];
      A[i] = -A[i];
    }
    max_wrap += kadane(A);
    return max(max_wrap, max_kadane);
  }
};
