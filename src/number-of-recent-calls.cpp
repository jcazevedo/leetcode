#include <vector>

using namespace std;

class RecentCounter {
 private:
  vector<int> pings;

 public:
  RecentCounter() {}

  int ping(int t) {
    pings.push_back(t);
    vector<int>::iterator itr = lower_bound(pings.begin(), pings.end(), t - 3000);
    return (pings.end() - itr);
  }
};
