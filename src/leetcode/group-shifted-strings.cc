class Solution {
 public:
  // We need to push everything to a single reference.
  // What's common in "ba" and "az"?
  // b = 1, a = 0
  // a = 0, z = 25 = -1 (mod 26)
  // az -> (0,-1)
  // ba -> (0,-1)
  // Fix the first at 'a'. Then "ba" becomes "az".
  // Example:
  // "abc"  -> "abc"
  // "bcd"  -> "abc"
  // "acef" -> "acef"
  // "xyz"  -> "abc"
  // "az"   -> "az"
  // "ba"   -> "az"
  // "a"    -> "a"
  // "z"    -> "a"
  vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    for (string s : strings) {
      string normalForm = convertToNormalForm(s);
      if (mp.find(normalForm) != mp.end()) {
        ans[mp[normalForm]].push_back(s);
      } else {
        mp[normalForm] = ans.size();
        vector<string> vec;
        vec.push_back(s);
        ans.push_back(vec);
      }
    }
    return ans;
  }

 private:
  string convertToNormalForm(string s) {
    if (s[0] == 'a') return s;
    int diff = 'a' - s[0];
    for (int i = 0; i < s.length(); ++i) {
      s[i] = s[i] + diff;
      if (s[i] < 'a') s[i] = 'z' - ('a' - s[i]) + 1;
    }
    return s;
  }
};
