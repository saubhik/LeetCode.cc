//
// Created by saubhik on 2020/03/06.
//
#include <string>
#include <vector>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find and
  // Replace Pattern. Memory Usage: 8.1 MB, less than 100.00% of C++ online
  // submissions for Find and Replace Pattern.
  //
  // O(|words|*|word|) time, O(1) space.
  static std::vector<std::string>
  findAndReplacePattern(std::vector<std::string> &words,
                        const std::string &pattern) {
    std::vector<std::string> ans;
    std::vector<int> map1(26, -1), map2(26, -1);
    int i;
    for (auto &word : words) {
      i = 0;
      map1.assign(map1.size(), -1);
      map2.assign(map2.size(), -1);
      for (; i < word.size(); ++i) {
        if ((map1[word[i] - 'a'] != -1 &&
             map1[word[i] - 'a'] != pattern[i] - 'a') ||
            (map2[pattern[i] - 'a'] != -1 &&
             map2[pattern[i] - 'a'] != word[i] - 'a'))
          break;
        map1[word[i] - 'a'] = pattern[i] - 'a';
        map2[pattern[i] - 'a'] = word[i] - 'a';
      }
      if (i == word.size())
        ans.push_back(word);
    }
    return ans;
  }
};

int main() {
  std::vector<std::string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"},
                           ans;
  std::string pattern = "abb";
  ans = Solution::findAndReplacePattern(words, pattern);
  for (auto &elem : ans)
    printf("%s ", elem.c_str());
  printf("\n");

  words = {"ef", "fq", "ao", "at", "lx"};
  pattern = "ya";
  ans = Solution::findAndReplacePattern(words, pattern);
  for (auto &elem : ans)
    printf("%s ", elem.c_str());
}
