// 284. Peeking Iterator
// https://leetcode.com/problems/peeking-iterator/

#include <vector>

using namespace std;

class Iterator {
  struct Data;
  Data* data;

public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
  bool _hasNext;
  int _next;

public:
  PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    _hasNext = Iterator::hasNext();
    if (_hasNext)
      _next = Iterator::next();
  }

  int peek() { return _next; }

  int next() {
    int ans = _next;
    _hasNext = Iterator::hasNext();
    if (_hasNext)
      _next = Iterator::next();
    return ans;
  }

  bool hasNext() const { return _hasNext; }
};
