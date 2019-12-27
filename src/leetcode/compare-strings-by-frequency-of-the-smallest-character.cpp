//
// Created by saubhik on 2019/12/27.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // O(max(|queries|, |words|)) time, O(1) space.
  static vector<int> numSmallerByFrequency(vector<string> &queries,
                                           vector<string> &words) {
    // counts[i] stores the count of words with frequency greater than i
    int counts[10] = {}, count_ch;
    char min_ch;

    for (string w : words) {
      min_ch = 'z', count_ch = 0;

      for (auto ch : w) {
        if (ch < min_ch)
          min_ch = ch, count_ch = 0;
        if (ch == min_ch)
          ++count_ch;
      }

      for (int i = 0; i < count_ch; ++i)
        ++counts[i];
    }

    vector<int> ans;
    for (auto query : queries) {
      min_ch = 'z', count_ch = 0;

      for (auto ch : query) {
        if (ch < min_ch)
          min_ch = ch, count_ch = 0;
        if (ch == min_ch)
          ++count_ch;
      }

      ans.push_back(counts[count_ch]);
    }

    return ans;
  }
};

int main() {
  vector<string> queries, words;
  vector<int> ans;

  queries = {"cbd"}, words = {"zaaaz"};
  ans = Solution::numSmallerByFrequency(queries, words);
  for (int n : ans)
    printf("%d ", n);

  printf("\n");

  queries = {"bbb", "cc"}, words = {"a", "aa", "aaa", "aaaa"};
  ans = Solution::numSmallerByFrequency(queries, words);
  for (int n : ans)
    printf("%d ", n);
}
