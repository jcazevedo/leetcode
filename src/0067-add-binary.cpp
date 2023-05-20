// 67. Add Binary
// https://leetcode.com/problems/add-binary/

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int A = a.size();
    int B = b.size();
    int L = max(A, B), carry = 0;
    string res = "";
    for (int i = 0; i < L; ++i) {
      int va = i < A ? a[i] - '0' : 0;
      int vb = i < B ? b[i] - '0' : 0;
      int target = va + vb + carry;
      res += (target % 2) + '0';
      carry = target / 2;
    }
    while (carry > 0) {
      res += (carry % 2) + '0';
      carry /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
