// 399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    unordered_map<string, int> var_to_idx;
    int n_vars = 0;
    for (const vector<string>& equation : equations) {
      if (var_to_idx.find(equation[0]) == var_to_idx.end()) var_to_idx[equation[0]] = n_vars++;
      if (var_to_idx.find(equation[1]) == var_to_idx.end()) var_to_idx[equation[1]] = n_vars++;
    }
    vector<vector<double>> dists = vector<vector<double>>(n_vars, vector<double>(n_vars, -1));
    for (int i = 0; i < n_vars; ++i) dists[i][i] = 1.0;
    int n_equations = equations.size();
    for (int i = 0; i < n_equations; ++i) {
      int u = var_to_idx[equations[i][0]];
      int v = var_to_idx[equations[i][1]];
      dists[u][v] = values[i];
      dists[v][u] = 1.0 / values[i];
    }
    for (int k = 0; k < n_vars; ++k) {
      for (int i = 0; i < n_vars; ++i) {
        if (dists[i][k] == -1) continue;
        for (int j = 0; j < n_vars; ++j) {
          if (dists[k][j] == -1) continue;
          if (dists[i][j] == -1 || dists[i][j] > dists[i][k] * dists[k][j]) dists[i][j] = dists[i][k] * dists[k][j];
        }
      }
    }
    int n_queries = queries.size();
    vector<double> ans = vector<double>(n_queries, -1);
    for (int i = 0; i < n_queries; ++i) {
      int u = -1;
      if (var_to_idx.find(queries[i][0]) != var_to_idx.end())
        u = var_to_idx[queries[i][0]];
      else
        continue;
      int v = -1;
      if (var_to_idx.find(queries[i][1]) != var_to_idx.end())
        v = var_to_idx[queries[i][1]];
      else
        continue;
      ans[i] = dists[u][v];
    }
    return ans;
  }
};
