#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> last_idx;
    for (size_t i = 0; i < s.size(); ++i)
      last_idx[s[i]] = i;
    vector<bool> visited = vector<bool>('z' - 'a' + 1, false);
    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i) {
      if (visited[s[i] - 'a'])
        continue;
      while (!st.empty() && s[i] < st.top() && last_idx[st.top()] > i) {
        char to_rem = st.top();
        st.pop();
        visited[to_rem - 'a'] = false;
      }
      st.push(s[i]);
      visited[s[i] - 'a'] = true;
    }
    string ans = "";
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
