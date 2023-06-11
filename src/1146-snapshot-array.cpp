// 1146. Snapshot Array
// https://leetcode.com/problems/snapshot-array/

#include <utility>
#include <vector>

using namespace std;

class SnapshotArray {
private:
  int snapId;
  vector<vector<pair<int, int>>> values;

public:
  SnapshotArray(int length)
      : snapId(0), values(vector<vector<pair<int, int>>>(length, vector<pair<int, int>>(1, make_pair(0, 0)))) {}

  void set(int index, int val) { values[index].push_back(make_pair(snapId, val)); }

  int snap() { return snapId++; }

  int get(int index, int snap_id) {
    int lo = 0, hi = values[index].size() - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (values[index][mid].first > snap_id)
        hi = mid - 1;
      else
        lo = mid;
    }
    return values[index][lo].second;
  }
};
