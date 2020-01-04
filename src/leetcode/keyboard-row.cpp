//
// Created by saubhik on 2020/01/04.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard
  // Row. Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for
  // Keyboard Row. O(n * |word|) time, O(1) space.
  static vector<string> findWords(vector<string> &words) {
    int pos[26] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2,
                   2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
    vector<string> ans;
    for (auto &word : words) {
      int n = word.size(), i;
      for (i = 1; i < n; ++i)
        if (pos[tolower(word[i]) - 'a'] != pos[tolower(word[i - 1]) - 'a'])
          break;
      if (i == n)
        ans.push_back(word);
    }
    return ans;
  }
};

int main() {
  vector<string> words = {"Hello", "Alaska", "Dad", "Peace"}, ans;
  ans = Solution::findWords(words);
  for (auto w : ans)
    printf("%s ", w.c_str());
}