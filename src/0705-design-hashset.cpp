// 705. Design HashSet
// https://leetcode.com/problems/design-hashset/

#include <algorithm>
#include <vector>

using namespace std;

class MyHashSet {
private:
  const static int N_BUCKETS = 1009;
  vector<vector<int>> buckets;

public:
  MyHashSet() { buckets.assign(N_BUCKETS, vector<int>()); }

  void add(int key) {
    int bucket = key % N_BUCKETS;
    if (find(buckets[bucket].begin(), buckets[bucket].end(), key) == buckets[bucket].end())
      buckets[bucket].push_back(key);
  }

  void remove(int key) {
    int bucket = key % N_BUCKETS;
    vector<int>::iterator pos = find(buckets[bucket].begin(), buckets[bucket].end(), key);
    if (pos != buckets[bucket].end())
      buckets[bucket].erase(pos);
  }

  bool contains(int key) {
    int bucket = key % N_BUCKETS;
    return find(buckets[bucket].begin(), buckets[bucket].end(), key) != buckets[bucket].end();
  }
};
