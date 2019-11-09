//
// Created by saubhik on 2019/11/09.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 97% run-time, 100% memory
  static vector<string> commonChars(vector<string> &A) {
    int charMap[26];
    memset(charMap, -1, sizeof(charMap));

    for (const string &s : A) {
      int cnt[26] = {};
      for (char ch : s)
        cnt[ch - 'a']++;
      for (int i = 0; i < 26; ++i)
        if (charMap[i] != -1)
          charMap[i] = min(charMap[i], cnt[i]);
        else
          charMap[i] = cnt[i];
    }

    vector<string> ans;
    for (int i = 0; i < 26; ++i)
      if (charMap[i])
        while (charMap[i]--)
          ans.emplace_back(1, (char)('a' + i));

    return ans;
  }
};

int main() {
  vector<string> inp = {"bella", "label", "roller"}, out;
  out = Solution::commonChars(inp);
  for (const string &elem : out)
    printf("%s ", elem.c_str());

  printf("\n");

  inp = {"cool", "lock", "cook"};
  out = Solution::commonChars(inp);
  for (const string &elem : out)
    printf("%s ", elem.c_str());
}
