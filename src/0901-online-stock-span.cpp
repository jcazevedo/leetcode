// 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/

#include <stack>

using namespace std;

class StockSpanner {
 private:
  stack<pair<int, int>> s;

 public:
  StockSpanner() {}

  int next(int price) {
    int res = 1;
    while (!s.empty() && s.top().first <= price) {
      res += s.top().second;
      s.pop();
    }
    s.push({price, res});
    return res;
  }
};
