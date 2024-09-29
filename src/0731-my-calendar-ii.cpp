// 731. My Calendar II
// https://leetcode.com/problems/my-calendar-ii/

#include <utility>
#include <vector>

using namespace std;

class MyCalendarTwo {
 private:
  vector<pair<int, int>> bookings;
  vector<pair<int, int>> overlaps;

 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (const pair<int, int>& booking : overlaps) {
      if (max(booking.first, start) < min(booking.second, end)) { return false; }
    }
    for (const pair<int, int>& booking : bookings) {
      if (max(booking.first, start) < min(booking.second, end)) {
        overlaps.push_back(make_pair(max(booking.first, start), min(booking.second, end)));
      }
    }
    bookings.push_back(make_pair(start, end));
    return true;
  }
};
