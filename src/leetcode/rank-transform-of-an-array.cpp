//
// Created by saubhik on 2020/01/31.
//
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 212 ms, faster than 86.08% of C++ online submissions for Rank
  // Transform of an Array. Memory Usage: 27.8 MB, less than 100.00% of C++
  // online submissions for Rank Transform of an Array.
  //
  // O(nlgn) time, O(n) space.
  static vector<int> arrayRankTransform(vector<int> &arr) {
    vector<int> a(arr);
    sort(a.begin(), a.end());
    unordered_map<int, int> ump;
    for (int &num : a)
      ump.emplace(num, ump.size() + 1);
    for (int &num : arr)
      num = ump[num];
    return arr;
  }
};

int main() {
  vector<int> arr = {40, 10, 20, 30}, ans;
  ans = Solution::arrayRankTransform(arr);
  for (int &num : ans)
    printf("%d ", num);
  printf("\n");

  arr = {100, 100, 100};
  ans = Solution::arrayRankTransform(arr);
  for (int &num : ans)
    printf("%d ", num);
  printf("\n");

  arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
  ans = Solution::arrayRankTransform(arr);
  for (int &num : ans)
    printf("%d ", num);
}
