// 2069. Walking Robot Simulation II
// https://leetcode.com/problems/walking-robot-simulation-ii/

#include <string>
#include <vector>

using namespace std;

class Robot {
  int w, h, perimeter, pos;

 public:
  Robot(int width, int height) : w(width), h(height), perimeter(2 * (width - 1) + 2 * (height - 1)), pos(0) {}

  void step(int num) {
    pos = (pos + num) % perimeter;
    if (pos == 0) { pos = perimeter; }
  }

  vector<int> getPos() {
    int p = pos;
    if (p <= w - 1) { return {p, 0}; }
    p -= w - 1;
    if (p <= h - 1) { return {w - 1, p}; }
    p -= h - 1;
    if (p <= w - 1) { return {w - 1 - p, h - 1}; }
    p -= w - 1;
    return {0, h - 1 - p};
  }

  string getDir() {
    if (pos <= w - 1) { return "East"; }
    if (pos <= w - 1 + h - 1) { return "North"; }
    if (pos <= 2 * (w - 1) + h - 1) { return "West"; }
    return "South";
  }
};
