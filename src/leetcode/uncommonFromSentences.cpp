//
// Created by saubhik on 2019/11/21.
//
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // 69.75% run-time, 100% memory
  static vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string, int> ump;
    istringstream ss(A + " " + B);
    string word;

    while (ss >> word)
      ++ump[word];

    vector<string> ans;
    for (auto it = ump.begin(); it != ump.end(); ++it)
      if (it->second == 1)
        ans.push_back(it->first);

    return ans;
  }
};

class Solution2 {
public:
  // same as above but using range based loop
  // 69.75% run-time, 100% memory
  static vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string, int> ump;
    istringstream ss(A + " " + B);
    string word;

    while (ss >> word)
      ++ump[word];

    vector<string> ans;
    for (auto entry : ump)
      if (entry.second == 1)
        ans.push_back(entry.first);

    return ans;
  }
};

int main() {
  vector<string> ans;
  ans = Solution::uncommonFromSentences("this apple is sweet",
                                        "this apple is sour");
  for (auto word : ans)
    printf("%s ", word.c_str());

  printf("\n");

  ans = Solution::uncommonFromSentences("apple apple", "banana");
  for (auto word : ans)
    printf("%s ", word.c_str());
}
