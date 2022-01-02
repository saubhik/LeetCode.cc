/**
 * definition for a binary tree node.
 * struct treenode {
 *     int val;
 *     treenode *left;
 *     treenode *right;
 *     treenode(int x) : val(x), left(null), right(null) {}
 * };
 *
 * algorithm:
 * 1. go to the target node.
 * 2. store the path to the target node.
 * 3. start bfs from target node.
 */
class solution {
 public:
  vector<int> distancek(treenode* root, treenode* target, int k) {
    stack<treenode*> path;
    vector<int> ans;
    getpathtotarget(root, target, path);
    getnodesatdistancek(target, path, k, ans);
    return ans;
  }

 private:
  void getnodesatdistancek(treenode* node, stack<treenode*>& path, int k,
                           vector<int>& ans) {
    queue<treenode*> q;
    unordered_set<treenode*> visited;
    q.push(node);

    while (!q.empty() && k--) {
      int levelsize = q.size();
      for (int i = 0; i < levelsize; ++i) {
        node = q.front();
        q.pop();

        if (node->left && visited.find(node->left) == visited.end()) {
          q.push(node->left);
        }

        if (node->right && visited.find(node->right) == visited.end()) {
          q.push(node->right);
        }

        if (!path.empty()) {
          if ((path.top())->left == node || (path.top())->right == node) {
            q.push(path.top());
            path.pop();
          }
        }

        visited.insert(node);
      }
    }

    while (!q.empty()) {
      ans.push_back((q.front())->val);
      q.pop();
    }
  }

  bool getpathtotarget(treenode* node, treenode* target,
                       stack<treenode*>& path) {
    if (target == node) {
      return true;
    }

    path.push(node);

    if (node->left != nullptr) {
      if (getpathtotarget(node->left, target, path)) {
        return true;
      } else {
        path.pop();
      }
    }

    if (node->right != nullptr) {
      if (getpathtotarget(node->right, target, path)) {
        return true;
      } else {
        path.pop();
      }
    }

    return false;
  }
};

