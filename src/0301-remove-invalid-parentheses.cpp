// 301. Remove Invalid Parentheses
// https://leetcode.com/problems/remove-invalid-parentheses/

#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

struct State {
  int position;
  int removalsLeft;
  int balance;

  bool operator<(const State& other) const {
    return tie(position, removalsLeft, balance) < tie(other.position, other.removalsLeft, other.balance);
  }
};

class Solution {
 private:
  int minimumRemovals(const string& s) {
    int open = 0;
    int removals = 0;
    for (char ch : s) {
      if (ch == '(') {
        ++open;
      } else if (ch == ')') {
        if (open > 0) {
          --open;
        } else {
          ++removals;
        }
      }
    }
    return removals + open;
  }

  vector<string> build(const string& s, int i, int removalsLeft, int balance, map<State, vector<string>>& cache) {
    if (removalsLeft < 0 || balance < 0) { return {}; }
    if (i == (int)s.size()) {
      if (removalsLeft == 0 && balance == 0) { return {""}; }
      return {};
    }
    State state{i, removalsLeft, balance};
    map<State, vector<string>>::iterator cached = cache.find(state);
    if (cached != cache.end()) { return cached->second; }
    set<string> result;
    char ch = s[i];
    if (ch == '(') {
      for (const string& suffix : build(s, i + 1, removalsLeft, balance + 1, cache)) { result.insert("(" + suffix); }
      for (const string& suffix : build(s, i + 1, removalsLeft - 1, balance, cache)) { result.insert(suffix); }
    } else if (ch == ')') {
      if (balance > 0) {
        for (const string& suffix : build(s, i + 1, removalsLeft, balance - 1, cache)) { result.insert(")" + suffix); }
      }
      for (const string& suffix : build(s, i + 1, removalsLeft - 1, balance, cache)) { result.insert(suffix); }
    } else {
      for (const string& suffix : build(s, i + 1, removalsLeft, balance, cache)) { result.insert(ch + suffix); }
    }
    vector<string> ans(result.begin(), result.end());
    cache[state] = ans;
    return ans;
  }

 public:
  vector<string> removeInvalidParentheses(string s) {
    map<State, vector<string>> cache;
    return build(s, 0, minimumRemovals(s), 0, cache);
  }
};
