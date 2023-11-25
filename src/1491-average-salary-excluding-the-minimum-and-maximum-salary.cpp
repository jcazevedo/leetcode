// 1491. Average Salary Excluding the Minimum and Maximum Salary
// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  double average(vector<int>& salary) {
    double sum = 0.0;
    int minimum = salary[0];
    int maximum = salary[0];
    for (int s : salary) {
      sum += s;
      minimum = min(minimum, s);
      maximum = max(maximum, s);
    }
    sum -= minimum;
    sum -= maximum;
    return sum / (salary.size() - 2);
  }
};
