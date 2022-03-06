class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    backtrack(0, num, "", 0, 0, target, ans);
    return ans;
  }

 private:
  void backtrack(int start, string& num, string path, long result, long curr,
                 int target, vector<string>& ans) {
    if (start == num.size() && result == target) ans.push_back(path);
    string numStr;
    long numInt = 0;
    for (int i = start; i < num.size(); ++i) {
      if (num[start] == '0' && i > start) break;
      numStr += num[i];
      numInt = numInt * 10 + (num[i] - '0');
      if (start == 0)
        backtrack(i + 1, num, path + numStr, numInt, numInt, target, ans);
      else {
        backtrack(i + 1, num, path + "+" + numStr, result + numInt, numInt,
                  target, ans);
        backtrack(i + 1, num, path + "-" + numStr, result - numInt, -numInt,
                  target, ans);
        backtrack(i + 1, num, path + "*" + numStr,
                  result - curr + curr * numInt, curr * numInt, target, ans);
      }
    }
  }
};
