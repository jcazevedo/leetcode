#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
  int n_elems;
  unordered_map<int, int> elem_to_idx;
  vector<int> idx_to_elem;

public:
  RandomizedSet() {
    srand(time(nullptr));
    n_elems = 0;
  }

  bool insert(int val) {
    if (elem_to_idx.count(val) > 0)
      return false;
    elem_to_idx[val] = n_elems++;
    idx_to_elem.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (elem_to_idx.count(val) == 0)
      return false;
    int hole = elem_to_idx[val];
    idx_to_elem[hole] = idx_to_elem[n_elems - 1];
    elem_to_idx[idx_to_elem[hole]] = hole;
    elem_to_idx.erase(val);
    idx_to_elem.pop_back();
    n_elems--;
    return true;
  }

  int getRandom() { return idx_to_elem[rand() % n_elems]; }
};
