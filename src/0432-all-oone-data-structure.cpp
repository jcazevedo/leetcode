// 432. All O`one Data Structure
// https://leetcode.com/problems/all-oone-data-structure/

#include <set>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

class AllOne {
 private:
  unordered_map<string, int> counts;
  set<tuple<int, string>> countPairs;

 public:
  AllOne() {}

  void inc(string key) {
    int current = counts[key];
    if (current != 0) countPairs.erase(countPairs.find({current, key}));
    counts[key]++;
    countPairs.insert({current + 1, key});
  }

  void dec(string key) {
    int current = counts[key];
    counts[key]--;
    countPairs.erase(countPairs.find({current, key}));
    if (current == 1)
      counts.erase(key);
    else
      countPairs.insert({current - 1, key});
  }

  string getMaxKey() {
    if (countPairs.empty()) return "";
    return get<1>(*countPairs.rbegin());
  }

  string getMinKey() {
    if (countPairs.empty()) return "";
    return get<1>(*countPairs.begin());
  }
};
