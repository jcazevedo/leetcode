// 941. Valid Mountain Array
// https://leetcode.com/problems/valid-mountain-array/

#include <vector>

using namespace std;

class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    int N = A.size();
    if (N < 3) return false;
    int i = 1;
    while (i < N && A[i] > A[i - 1]) i++;
    if (i < 2 || i == N) return false;
    while (i < N && A[i] < A[i - 1]) i++;
    return i == N;
  }
};
