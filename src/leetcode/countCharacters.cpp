//
// Created by saubhik on 2019/11/05.
//
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // time: O(|words|(|max_word| + |chars|))
  static int countCharacters(vector<string> &words, const string &chars) {
    int sum = 0;

    for (const string &word : words) {
      bool good = true;

      map<char, int> mp;
      for (char ch : chars)
        mp[ch]++;

      for (char ch : word) {
        if (mp.find(ch) == mp.end()) {
          good = false;
          break;
        } else if (mp.at(ch)-- == 0) {
          good = false;
          break;
        }
      }

      if (good) {
        sum += word.size();
      }
    }

    return sum;
  }

  // use hash maps, but use vector<int> implementation
  // much faster compared to map<,> implemntation
  static int countCharacters2(vector<string> &words, const string &chars) {
    int res = 0;
    vector<int> mp(26);
    for (auto ch : chars)
      ++mp[ch - 'a'];
    for (const auto &w : words) {
      vector<int> mp1 = mp;
      bool good = true;
      for (auto ch : w) {
        if (--mp1[ch - 'a'] < 0) {
          good = false;
          break;
        }
      }
      if (good)
        res += w.size();
    }
    return res;
  }
};

int main() {
  // Output: 6
  string w[] = {"cat", "bt", "hat", "tree"};
  vector<string> words(w, w + sizeof(w) / sizeof(string));
  printf("%d\n", Solution::countCharacters(words, "atach"));
  printf("%d\n", Solution::countCharacters2(words, "atach"));

  // Output: 10
  string w2[] = {"hello", "world", "leetcode"};
  vector<string> words2(w2, w2 + sizeof(w2) / sizeof(string));
  printf("%d\n", Solution::countCharacters(words2, "welldonehoneyr"));
  printf("%d\n", Solution::countCharacters2(words2, "welldonehoneyr"));
}
