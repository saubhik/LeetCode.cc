//
// Created by saubhik on 2019/11/19.
//
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // 96.05% runtime, 72.73% memory
  // unordered_map (using hash map)
  // O(n) time, O(n) space
  static int findPairs(vector<int> &nums, int k) {
    if (k < 0)
      return 0;

    int n = nums.size(), ans = 0;

    unordered_map<int, short> ump;
    for (auto const &num : nums)
      ++ump[num];

    for (auto it = ump.begin(); it != ump.end(); ++it)
      if (!k && it->second > 1)
        ++ans;
      else if (k && ump.find(it->first + k) != ump.end())
        ++ans;

    return ans;
  }
};

int main() {
  vector<int> nums = {3, 1, 4, 1, 5};
  printf("%d\n", Solution::findPairs(nums, 2));

  nums = {1, 2, 3, 4, 5};
  printf("%d\n", Solution::findPairs(nums, 1));

  nums = {1, 3, 1, 5, 4};
  printf("%d", Solution::findPairs(nums, 0));
}
