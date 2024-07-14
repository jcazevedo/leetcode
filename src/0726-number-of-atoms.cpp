// 726. Number of Atoms
// https://leetcode.com/problems/number-of-atoms/

#include <cstdio>
#include <map>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  string countOfAtoms(string formula) {
    stack<map<string, int>> counts;
    counts.push(map<string, int>());
    int N = formula.size();
    int i = 0;
    while (i < N)
      if (formula[i] == '(') {
        counts.push(map<string, int>());
        ++i;
      } else if (formula[i] == ')') {
        map<string, int> top = counts.top();
        counts.pop();
        ++i;
        int mult = 0;
        while (i < N && isdigit(formula[i])) mult = mult * 10 + (formula[i++] - '0');
        if (mult == 0) mult = 1;
        for (auto itr = top.begin(); itr != top.end(); ++itr) counts.top()[itr->first] += itr->second * mult;
      } else {
        string curr = "";
        curr += formula[i];
        ++i;
        while (i < N && islower(formula[i])) curr += formula[i++];
        int count = 0;
        while (i < N && isdigit(formula[i])) count = count * 10 + (formula[i++] - '0');
        if (count == 0) count = 1;
        counts.top()[curr] += count;
      }
    ostringstream ss;
    for (auto itr = counts.top().begin(); itr != counts.top().end(); ++itr) {
      ss << itr->first;
      if (itr->second > 1) ss << itr->second;
    }
    return ss.str();
  }
};
