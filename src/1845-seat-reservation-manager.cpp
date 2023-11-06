// 1845. Seat Reservation Manager
// https://leetcode.com/problems/seat-reservation-manager/

#include <set>

using namespace std;

class SeatManager {
private:
  set<int> unreserved;

public:
  SeatManager(int n) {
    for (int i = 1; i <= n; ++i)
      unreserved.insert(i);
  }

  int reserve() {
    int ans = *unreserved.begin();
    unreserved.erase(unreserved.begin());
    return ans;
  }

  void unreserve(int seatNumber) { unreserved.insert(seatNumber); }
};
