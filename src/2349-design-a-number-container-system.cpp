// 2349. Design a Number Container System
// https://leetcode.com/problems/design-a-number-container-system/

#include <set>
#include <unordered_map>

using namespace std;

class NumberContainers {
 private:
  unordered_map<int, int> vv;
  unordered_map<int, set<int>> ii;

 public:
  NumberContainers() {}

  void change(int index, int number) {
    if (vv.count(index)) { ii[vv[index]].erase(index); }
    vv[index] = number;
    ii[number].insert(index);
  }

  int find(int number) {
    if (!ii[number].empty()) { return *ii[number].begin(); }
    return -1;
  }
};
