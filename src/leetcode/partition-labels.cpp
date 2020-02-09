//
// Created by saubhik on 2020/02/09.
//
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Partition
  // Labels. Memory Usage: 8.8 MB, less than 70.97% of C++ online submissions
  // for Partition Labels.
  //
  // Runtime: 4 ms, faster than 93.52% of C++ online submissions for Partition
  // Labels. Memory Usage: 8.7 MB, less than 80.65% of C++ online submissions
  // for Partition Labels.
  //
  // O(n) time, O(1) space.
  static vector<int> partitionLabels(string S) {
    vector<pair<int, int>> intervals(26, {-1, -1});
    for (int i = 0; i < S.length(); ++i) {
      auto &p = intervals[S[i] - 'a'];
      if (p.first == -1)
        p.first = p.second = i;
      else
        p.second = i;
    }
    sort(begin(intervals), end(intervals));
    for (auto it = begin(intervals); it + 1 != end(intervals);) {
      if (it->second > (it + 1)->first) {
        it->second = max(it->second, (it + 1)->second);
        intervals.erase(it + 1);
      } else
        ++it;
    }
    vector<int> res;
    for (auto it = begin(intervals); it != end(intervals); ++it)
      if (it->first != -1)
        res.push_back(it->second - it->first + 1);
    return res;
  }
};

class Solution2 {
public:
  // Courtesy: votrubac
  // votrubac says: first pass we record the last position for each letter.
  // Second pass, we keep the maximum position of the letters we have seen so
  // far. If the pointer exceeds the maximum position, we found the part.
  //
  // Runtime: 4 ms, faster than 93.52% of C++ online submissions for Partition
  // Labels. Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions
  // for Partition Labels.
  //
  // O(n) time, O(1) space.
  static vector<int> partitionLabels(string S) {
    vector<int> res, pos(26, 0);
    for (auto i = 0; i < S.size(); ++i)
      pos[S[i] - 'a'] = i;
    // idx is the maximum position of the all the letters till now (including
    // now). If now equals idx, it is time to push one part to result res.
    for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
      idx = max(idx, pos[S[i] - 'a']);
      if (idx == i)
        res.push_back(i - exchange(last_i, i + 1) + 1);
    }
    return res;
  }
};

int main() {
  vector<int> ans;
  ans = Solution::partitionLabels("ababcbacadefegdehijhklij");
  for (int &elem : ans)
    printf("%d ", elem);

  printf("\n");

  ans = Solution2::partitionLabels("ababcbacadefegdehijhklij");
  for (int &elem : ans)
    printf("%d ", elem);
}
