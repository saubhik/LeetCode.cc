//
// Created by saubhik on 2019/12/07.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 100% run-time, 100% memory
  // O(n) time, O(1) memory
  static bool isAlienSorted(vector<string> &words, string order) {
    int mp[26];
    for (int i = 0; i < 26; ++i)
      mp[order[i] - 'a'] = i;

    for (int i = 1; i < words.size(); ++i) {
      int itr = 0;
      for (; itr < words[i].length(); ++itr) {
        if (mp[words[i][itr] - 'a'] < mp[words[i - 1][itr] - 'a'])
          return false;
        else if (mp[words[i][itr] - 'a'] == mp[words[i - 1][itr] - 'a'])
          continue;
        else
          break;
      }
      if (itr == words[i].length() && itr < words[i - 1].length())
        return false;
    }

    return true;
  }
};

class Solution2 {
public:
  // 60.97% run-time, 76.92% memory
  // Lee's solution.
  // Just store the mapping numbers in the vector of strings
  // O(n) time.
  // Not as efficient as the previous one, as we do not need to lookup
  // mappings for every character, in every word!
  static bool isAlienSorted(vector<string> &words, string order) {
    int mp[26];
    for (int i = 0; i < 26; ++i)
      mp[order[i] - 'a'] = i;

    for (string &word : words)
      for (char &c : word)
        c = mp[c - 'a'];

    return is_sorted(words.begin(), words.end());
  }
};

int main() {
  vector<string> words;

  words = {"hello", "leetcode"};
  printf("%d %d\n",
         Solution::isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"),
         Solution2::isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz"));

  words = {"word", "world", "row"};
  printf("%d %d\n",
         Solution::isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"),
         Solution2::isAlienSorted(words, "worldabcefghijkmnpqstuvxyz"));

  words = {"apple", "app"};
  printf("%d %d\n",
         Solution::isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"),
         Solution2::isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz"));
}
