//
// Created by saubhik on 2019/11/28.
//
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  // 100% run-time, 43.33% memory
  // O(n) time, O(n) space.
  static vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> us;
    vector<int> ans;
    for (int i = 0; i < nums1.size(); ++i)
      us.insert(nums1[i]);
    for (int i = 0; i < nums2.size(); ++i)
      if (us.erase(nums2[i])) {
        ans.push_back(nums2[i]);
      }

    return ans;
  }
};

int main() {
  vector<int> nums1, nums2, ans;

  nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
  ans = Solution::intersection(nums1, nums2);
  for (auto num : ans)
    printf("%d ", num);

  printf("\n");

  nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};
  ans = Solution::intersection(nums1, nums2);
  for (auto num : ans)
    printf("%d ", num);
}
