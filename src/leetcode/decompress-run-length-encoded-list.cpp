//
// Created by saubhik on 2020/01/25.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 44 ms, faster than 89.82% of C++ online submissions for Decompress Run-Length Encoded List.
  // Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Decompress Run-Length Encoded List.
  // O(n^2) time, O(1) space, where n ~ 100.
  static vector<int> decompressRLElist(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i += 2)
      for (int j = 0; j < nums[i]; ++j)
        ans.push_back(nums[i+1]);
    return ans;
  }
};

int main() {
  vector<int> nums = {1,2,3,4};
  vector<int> ans = Solution::decompressRLElist(nums);
  for (int num : ans)
    printf("%d ", num);
}
