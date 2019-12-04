//
// Created by saubhik on 2019/12/04.
//
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 91.58% run-time, 100% memory
  // O(|words| * |word|) time, O(|word|) space.
  static string shortestCompletingWord(string licensePlate,
                                       vector<string> &words) {
    string ans = "";
    int target[26] = {};

    for (auto ch : licensePlate)
      if (isalpha(ch))
        ++target[tolower(ch) - 'a'];

    for (auto word : words) {

      int counts[26] = {};
      for (char ch : word)
        ++counts[tolower(ch) - 'a'];

      bool completingWord = true;
      for (int i = 0; i < 26; ++i)
        if (counts[i] < target[i]) {
          completingWord = false;
          break;
        }

      if (completingWord && (ans == "" || word.length() < ans.length()))
        ans = word;
    }
    return ans;
  }
};

int main() {
  vector<string> words = {"step", "steps", "stripe", "stepple"};
  printf("%s\n", Solution::shortestCompletingWord("1s3 PSt", words).c_str());

  words = {"looks", "pest", "stew", "show"};
  printf("%s\n", Solution::shortestCompletingWord("1s3 456", words).c_str());

  words = {"measure", "other",   "every", "base",     "according",
           "level",   "meeting", "none",  "marriage", "rest"};
  printf("%s", Solution::shortestCompletingWord("GrC8950", words).c_str());
}
