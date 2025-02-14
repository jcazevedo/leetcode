// 1352. Product of the Last K Numbers
// https://leetcode.com/problems/product-of-the-last-k-numbers/

#include <vector>

using namespace std;

class ProductOfNumbers {
 private:
  vector<long long> prod;
  long long tot;

 public:
  ProductOfNumbers() { tot = 1L; }

  void add(int num) {
    if (num == 0) {
      tot = 1L;
      prod.clear();
    } else {
      tot *= num;
      if (prod.empty()) {
        prod.push_back(num);
      } else {
        prod.push_back(prod.back() * num);
      }
    }
  }

  int getProduct(int k) {
    if (k > (int)prod.size()) { return 0; }
    int rem = prod.size() - k;
    if (rem == 0) { return tot; }
    return tot / prod[rem - 1];
  }
};
