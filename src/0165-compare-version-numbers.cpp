// 165. Compare Version Numbers
// https://leetcode.com/problems/compare-version-numbers/

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int str_to_int(string str) {
    int ans;
    istringstream ss(str);
    ss >> ans;
    return ans;
  }

  vector<int> split_version(string version) {
    vector<int> ans;
    size_t pos;
    while ((pos = version.find('.')) != string::npos) {
      ans.push_back(str_to_int(version.substr(0, pos)));
      version.erase(0, pos + 1);
    }
    ans.push_back(str_to_int(version));
    return ans;
  }

public:
  int compareVersion(string version1, string version2) {
    vector<int> v1 = split_version(version1);
    vector<int> v2 = split_version(version2);
    int N1 = v1.size(), N2 = v2.size(), i = 0;
    while (i < N1 || i < N2) {
      int p1 = i < N1 ? v1[i] : 0;
      int p2 = i < N2 ? v2[i] : 0;
      if (p1 < p2)
        return -1;
      if (p1 > p2)
        return 1;
      i++;
    }
    return 0;
  }
};
