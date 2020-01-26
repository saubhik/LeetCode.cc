//
// Created by saubhik on 2020/01/25.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 128 ms, faster than 12.92% of C++ online submissions for All Paths
  // From Source to Target. Memory Usage: 23.1 MB, less than 10.00% of C++
  // online submissions for All Paths From Source to Target.
  static vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<vector<int>>> memo(graph.size());
    memo[graph.size() - 1] = {{(int)graph.size() - 1}};
    return paths(graph, memo, 0);
  }
  static vector<vector<int>> paths(vector<vector<int>> &graph,
                                   vector<vector<vector<int>>> &memo, int src) {
    if (!memo[src].empty())
      return memo[src];
    vector<vector<int>> current_paths;
    for (auto node : graph[src]) {
      vector<vector<int>> node_paths = paths(graph, memo, node);
      for (const auto &path : node_paths) {
        vector<int> a_path(path.size() + 1);
        a_path[0] = src;
        for (int i = 1; i < a_path.size(); ++i)
          a_path[i] = path[i - 1];
        current_paths.push_back(a_path);
      }
    }
    return memo[src] = current_paths;
  }
};

class Solution2 {
public:
  // Runtime: 72 ms, faster than 92.60% of C++ online submissions for All Paths
  // From Source to Target. Memory Usage: 12.6 MB, less than 90.00% of C++
  // online submissions for All Paths From Source to Target.
  static vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> result;
    vector<int> path;
    int dest = (int)graph.size() - 1;
    dfs(graph, result, path, 0, dest);
    return result;
  }
  static void dfs(vector<vector<int>> &graph, vector<vector<int>> &result,
                  vector<int> &path, int node, int &dest) {
    path.push_back(node);
    if (node == dest)
      result.push_back(path);
    else
      for (const auto &nbr : graph[node]) {
        dfs(graph, result, path, nbr, dest);
      }
    path.pop_back();
  }
};

int main() {
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}}, ans;
  ans = Solution::allPathsSourceTarget(graph);
  for (const auto &path : ans) {
    printf("[");
    for (const auto &num : path)
      printf("%d,", num);
    printf("], ");
  }

  printf("\n");

  ans = Solution2::allPathsSourceTarget(graph);
  for (const auto &path : ans) {
    printf("[");
    for (const auto &num : path)
      printf("%d,", num);
    printf("], ");
  }
}
