// 706. Design HashMap
// https://leetcode.com/problems/design-hashmap/

#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class MyHashMap {
private:
  const static int N_BUCKETS = 1009;
  vector<vector<pair<int, int>>> buckets;

public:
  MyHashMap() { buckets.assign(N_BUCKETS, vector<pair<int, int>>()); }

  void put(int key, int value) {
    int bucket = key % N_BUCKETS;
    vector<pair<int, int>>::iterator itr = upper_bound(
        buckets[bucket].begin(), buckets[bucket].end(), make_pair(key, -1));
    if (itr == buckets[bucket].end())
      buckets[bucket].push_back(make_pair(key, value));
    else if (itr->first == key)
      itr->second = value;
    else
      buckets[bucket].insert(itr, make_pair(key, value));
  }

  int get(int key) {
    int bucket = key % N_BUCKETS;
    vector<pair<int, int>>::iterator itr = upper_bound(
        buckets[bucket].begin(), buckets[bucket].end(), make_pair(key, -1));
    if (itr == buckets[bucket].end() || itr->first != key)
      return -1;
    return itr->second;
  }

  void remove(int key) {
    int bucket = key % N_BUCKETS;
    vector<pair<int, int>>::iterator itr = upper_bound(
        buckets[bucket].begin(), buckets[bucket].end(), make_pair(key, -1));
    if (itr == buckets[bucket].end() || itr->first != key)
      return;
    buckets[bucket].erase(itr);
  }
};
