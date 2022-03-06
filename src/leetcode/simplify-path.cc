class Solution {
 public:
  // "/home/"
  // - No trailing '/'.
  // - No duplicate '/'.
  // - No '.' or '..'.
  // - Starts with a single slash.
  string simplifyPathAliter(string path) {
    int n = path.length();
    string ns;
    // path[0] should be a '/'
    assert(path[0] == '/');
    ns.push_back(path[0]);
    for (int i = 1; i < n; ++i) {
      // Duplicate '/' encountered. Skip.
      if (path[i] == '/' && path[i - 1] == '/') continue;
      // path ends with '/'. Skip.
      if (i == n - 1 && path[i] == '/') continue;
      if (path[i - 1] == '/' && path[i] == '.') {
        // Are there more dots?
        int j = i;
        while (j < n && path[j] == '.') ++j;
        // Number of dots = j-i;
        if (j - i == 1 && (j == n || path[j] == '/')) {
          // Current directory.
          // "/./": path[j] == '/'
          //    ^... -> j
          i = j;  // Gets incremented in next iter.
          continue;
        }
        if (j - i == 2 && (j == n || path[j] == '/')) {
          // Go up one directory.
          // "/home/../hello"
          //  ........^ <- j
          // ns = "/home/" should become ns = "/"
          int m = ns.size();
          assert(ns[m - 1] == '/');
          if (m > 1) ns.pop_back();
          // Pop everything till the preceeding '/'.
          for (int j = m - 2; j >= 0; --j) {
            if (ns[j] == '/') break;
            ns.pop_back();
          }
          i = j;  // Gets incremented in next iter.
          continue;
        }
      }
      // No dots, or other duplicate '/', or trailing '/'.
      ns.push_back(path[i]);
    }
    if (ns.size() > 1 && ns.back() == '/') ns.pop_back();
    // ns should not end with any trailing '/' now.
    return ns;
  }
  // Using a stack.
  string simplifyPath(string path) {
    stringstream ss(path);
    string item;
    vector<string> comps;
    while (getline(ss, item, '/')) comps.push_back(item);
    vector<string> dirs;
    for (int i = 0; i < comps.size(); ++i) {
      if (comps[i] == "." || comps[i] == "") continue;
      if (comps[i] == "..") {
        if (!dirs.empty()) dirs.pop_back();
        continue;
      }
      dirs.push_back(comps[i]);
    }
    string ans;
    for (int i = 0; i < dirs.size(); ++i) ans.append("/" + dirs[i]);
    return ans == "" ? "/" : ans;
  }
};
