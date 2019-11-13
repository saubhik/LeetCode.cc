//
// Created by saubhik on 2019/11/13.
//
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  // 100% run-time, 100% memory
  static vector<string> findOcurrences(const string &text, const string &first,
                                       const string &second) {
    istringstream ss(text);
    string prev, prePrev, word;
    vector<string> ans;
    while (ss >> word) {
      if (prePrev == first && prev == second)
        ans.push_back(word);
      prePrev = prev;
      prev = word;
    }
    return ans;
  }
};

int main() {
  vector<string> out;
  out = Solution::findOcurrences("alice is a good girl she is a good student",
                                 "a", "good");
  for (const string &s : out)
    printf("%s, ", s.c_str());

  printf("\n");

  out = Solution::findOcurrences("we will we will rock you", "we", "will");
  for (const string &s : out)
    printf("%s, ", s.c_str());
}