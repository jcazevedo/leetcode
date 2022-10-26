#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& A) {
    int N = A.size();
    int right = N - 1, i = 0;
    while (i <= right) {
      if (A[i] % 2 == 1) {
        swap(A[right], A[i]);
        right--;
      } else {
        i++;
      }
    }
    return A;
  }
};
