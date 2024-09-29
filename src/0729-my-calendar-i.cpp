// 729. My Calendar I
// https://leetcode.com/problems/my-calendar-i/

#include <set>
#include <unordered_map>

using namespace std;

class MyCalendar {
 private:
  set<int> starts;
  unordered_map<int, int> ends;

 public:
  MyCalendar() {}

  bool book(int start, int end) {
    if (!starts.empty()) {
      set<int>::iterator next = starts.upper_bound(start);
      if (next != starts.end() && end > *next) { return false; }
      if (next != starts.begin()) {
        --next;
        if (ends[*next] > start) { return false; }
      }
    }
    starts.insert(start);
    ends[start] = end;
    return true;
  }
};
