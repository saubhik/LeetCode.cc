//
// Created by saubhik on 2019/12/06.
//
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Employee info
class Employee {
public:
  // It's the unique ID of each node.
  // unique id of this employee
  int id;
  // the importance value of this employee
  int importance;
  // the id of direct subordinates
  vector<int> subordinates;

  Employee(int id, int importance, vector<int> subordinates)
      : id(id), importance(importance), subordinates(subordinates) {}
};

class Solution {
public:
  // 99.76% run-time, 100% memory
  // O(n) time, O(n) space
  // using BFS idea.
  static int getImportance(vector<Employee *> employees, int id) {
    int n = employees.size();
    unordered_map<int, Employee *> ump;

    for (int i = 0; i < n; ++i)
      ump[employees[i]->id] = employees[i];

    int ans = 0;
    queue<int> q;
    q.push(id);

    while (!q.empty()) {
      int empID = q.front();
      auto emp = ump[empID];

      ans += emp->importance;

      for (int subID : emp->subordinates)
        q.push(subID);

      q.pop();
    }

    return ans;
  }
};

class Solution2 {
public:
  // 91.69% run-time, 92.86% memory
  // O(n) time, O(n) space.
  // using DFS.
  static int getImportance(vector<Employee *> employees, int id) {
    int n = employees.size();
    unordered_map<int, Employee *> ump;

    for (int i = 0; i < n; ++i)
      ump[employees[i]->id] = employees[i];

    int ans = 0;
    dfs(ump, id, ans);
    return ans;
  }

  static void dfs(unordered_map<int, Employee *> &ump, int &id, int &ans) {
    ans += ump[id]->importance;
    for (int subID : ump[id]->subordinates)
      dfs(ump, subID, ans);
  }
};

int main() {
  vector<Employee *> employees = {new Employee(1, 5, {2, 3}),
                                  new Employee(2, 3, {}),
                                  new Employee(3, 3, {})};
  printf("%d", Solution2::getImportance(employees, 1));

  printf("\n");

  employees = {new Employee(1, 2, {2}), new Employee(2, 3, {})};
  printf("%d", Solution2::getImportance(employees, 2));
}
