# All Paths From Source To Target

The Python solution from [here](https://leetcode.com/problems/all-paths-from-source-to-target/discuss/298345/Python-faster-than-100-76-ms):

```python
class Solution:
  def __init__(self):
    self.memo={}
  def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
    self.memo = {len(graph)-1:[[len(graph)-1]]}
    def calc(N):
      if N in self.memo:
        return self.memo[N]
      a=[]
      for n in graph[N]:
        for path in calc(n):
          a.append([N]+path)
      self.memo[N]=a
      return a
    return calc(0)
```

Consider the example for the dry run:

```python
graph=[[1,2],[3],[3],[]]
```

Let's consider Lee's solution. I should have considered Lee's solution in the beginning. It would have saved me more time.

```python
def allPathsSourceTarget(self, graph):
  def dfs(cur, path):
    if cur == len(graph)-1:
      res.append(path)
    else:
      for i in graph[cur]:
        dfs(i, path + [i])
	res=[]
  dfs(0,0)
  return res
```

Let's dry run again.

Final C++ solution:

```c++
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
```

---

This is also known as $Backtracking$. We are not memoing here, as there is not much time save. Notice that we are using the reference $\&path$ and `push_back()` at the beginning & `pop_back()` at the end.