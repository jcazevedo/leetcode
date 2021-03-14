#include <unordered_map>
#include <vector>

using namespace std;

class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
private:
  unordered_map<int, int> importance;
  unordered_map<int, vector<int>> subordinates;

  int get_tot_importance(int id) {
    int res = importance[id];
    for (int subordinate : subordinates[id])
      res += get_tot_importance(subordinate);
    return res;
  }

public:
  int getImportance(vector<Employee*> employees, int id) {
    for (Employee* e : employees) {
      importance[e->id] = e->importance;
      subordinates[e->id] = e->subordinates;
    }
    return get_tot_importance(id);
  }
};
