// 1281. Subtract the Product and Sum of Digits of an Integer
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
 private:
  int product(int n) {
    int ans = 1;

    while (n) {
      ans *= n % 10;
      n /= 10;
    }

    return ans;
  }

  int sum(int n) {
    int ans = 0;

    while (n) {
      ans += n % 10;
      n /= 10;
    }

    return ans;
  }

 public:
  int subtractProductAndSum(int n) { return product(n) - sum(n); }
};
