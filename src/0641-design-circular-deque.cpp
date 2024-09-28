// 641. Design Circular Deque
// https://leetcode.com/problems/design-circular-deque/

#include <vector>

using namespace std;

class MyCircularDeque {
 private:
  int N, back, len;
  vector<int> arr;

 public:
  MyCircularDeque(int k) {
    N = k;
    arr = vector<int>(N);
    back = len = 0;
  }

  bool insertFront(int value) {
    if (isFull()) { return false; }
    ++len;
    arr[(back + len + N - 1) % N] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) { return false; }
    back = (back + N - 1) % N;
    arr[back] = value;
    ++len;
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) { return false; }
    --len;
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) { return false; }
    back = (back + 1) % N;
    --len;
    return true;
  }

  int getFront() {
    if (isEmpty()) { return -1; }
    return arr[(back + len + N - 1) % N];
  }

  int getRear() {
    if (isEmpty()) { return -1; }
    return arr[back];
  }

  bool isEmpty() { return len == 0; }

  bool isFull() { return len == N; }
};
