//
// Created by saubhik on 2019/12/09.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 98.65% run-time, 47.06% memory
  // O(nlogn) time, O(n) space.
  static vector<string> reorderLogFiles(vector<string> &logs) {
    stable_sort(logs.begin(), logs.end(), [](const string &a, const string &b) {
      int posA = a.find(" "), posB = b.find(" ");
      string wordsA = a.substr(posA + 1), wordsB = b.substr(posB + 1);

      if (isalpha(wordsA[0]) && isalpha(wordsB[0])) {
        if (wordsA == wordsB)
          return a.substr(0, posA) < b.substr(0, posB);
        return wordsA < wordsB;
      }

      if (isalpha(wordsA[0]) && isdigit(wordsB[0]))
        return true;

      if (isdigit(wordsA[0]) && isalpha(wordsB[0]))
        return false;

      return false;
    });
    return logs;
  }
};

int main() {
  vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                         "let2 own kit dig", "let3 art zero"},
                 ans;
  ans = Solution::reorderLogFiles(logs);
  for (auto s : ans)
    printf("[%s] ", s.c_str());

  printf("\n");

  logs = {
      "l5sh 6 3869 08 1295",  "16o 94884717383724 9", "43 490972281212 3 51",
      "9 ehyjki ngcoobi mi",  "2epy 85881033085988",  "7z fqkbxxqfks f y dg",
      "9h4p 5 791738 954209", "p i hz uubk id s m l", "wd lfqgmu pvklkdp u",
      "m4jl 225084707500464", "6np2 bqrrqt q vtap h", "e mpgfn bfkylg zewmg",
      "ttzoz 035658365825 9", "k5pkn 88312912782538", "ry9 8231674347096 00",
      "w 831 74626 07 353 9", "bxao armngjllmvqwn q", "0uoj 9 8896814034171",
      "0 81650258784962331",  "t3df gjjn nxbrryos b"};
  ans = Solution::reorderLogFiles(logs);
  for (auto s : ans)
    printf("[%s] ", s.c_str());
}
