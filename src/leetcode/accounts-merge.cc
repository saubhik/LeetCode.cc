class Solution {
 public:
  // ["John", "abc", "def"]
  // ["John", "def", "ghi"]
  // If two lists have same email, we need to merge.
  // "abc": 0
  // "def": 0,1
  // "ghi": 1
  // "jkl": 2
  // "mno": 3
  // If the email exists, merge with that account.
  // Denote each email with a node. Also keep the name of the person.
  // We have an undirected graph.
  // ["abc","John"] <-> ["def","John"] <-> ["ghi", "Join"]
  // Now find the connected components in this undirected graph.
  vector<vector<string>> accountsMerge(const vector<vector<string>>& accounts) {
    int n = accounts.size();

    // Build the graph.
    for (const vector<string>& account : accounts) {
      int m = account.size();
      // First email acts as pivot for graph.
      // You can reach all emails of the account through the first email.
      string firstEmail = account[1];
      for (int j = 2; j < m; ++j) {
        string email = account[j];
        graph[firstEmail].push_back(email);
        graph[email].push_back(firstEmail);
      }
    }

    // Connected components on the graph.
    vector<vector<string>> ans;
    vector<string> emails;
    for (const vector<string>& account : accounts) {
      if (visited.find(account[1]) != visited.end()) continue;
      emails.clear();
      emails.push_back(account[0]);
      dfs(account[1], emails);
      sort(emails.begin() + 1, emails.end());
      ans.push_back(emails);
    }

    return ans;
  }

 private:
  unordered_set<string> visited;
  // Graph in the stack, no need to use heap memory.
  // Problem with this is: you're duplicating lot of strings.
  // With heap memory, you're duplicating pointers:
  // struct Node {
  //     string name;
  //     string email;
  //     vector<Node*> children;
  // };
  // But you need to properly delete this heap memory.
  // However, stack memory is faster.
  unordered_map<string, vector<string>> graph;
  void dfs(const string& email, vector<string>& emails) {
    if (visited.find(email) != visited.end()) return;
    emails.push_back(email);
    visited.insert(email);
    for (string& child : graph[email]) dfs(child, emails);
  }
};
