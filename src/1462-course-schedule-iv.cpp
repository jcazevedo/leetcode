// 1462. Course Schedule IV
// https://leetcode.com/problems/course-schedule-iv/

#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
    for (int i = 0; i < numCourses; ++i) { isPrerequisite[i][i] = true; }
    for (const vector<int>& prerequisite : prerequisites) { isPrerequisite[prerequisite[0]][prerequisite[1]] = true; }
    for (int k = 0; k < numCourses; ++k) {
      for (int i = 0; i < numCourses; ++i) {
        if (!isPrerequisite[i][k]) { continue; }
        for (int j = 0; j < numCourses; ++j) {
          if (!isPrerequisite[k][j]) { continue; }
          isPrerequisite[i][j] = true;
        }
      }
    }
    int Q = queries.size();
    vector<bool> ans(Q);
    for (int i = 0; i < Q; ++i) { ans[i] = isPrerequisite[queries[i][0]][queries[i][1]]; }
    return ans;
  }
};
