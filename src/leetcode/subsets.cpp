//
// Created by saubhik on 2020/03/01.
//
#include <vector>

class Solution {
public:
  // Runtime: 4 ms, faster than 98.26% of C++ online submissions for Subsets.
  // Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for
  // Subsets.
  //
  // iterative.
  // O(2**n) time, O(2**n) space.
  static std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    res.emplace_back();
    for (int num : nums) {
      auto tmp = res;
      for (auto subset : tmp) {
        subset.push_back(num);
        res.push_back(subset);
      }
    }
    return res;
  }
};

class Solution2 {
public:
  // Runtime: 4 ms, faster than 98.26% of C++ online submissions for Subsets.
  // Memory Usage: 8 MB, less than 100.00% of C++ online submissions for
  // Subsets.
  //
  // each subset correspond to binary representation
  static std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    unsigned n = nums.size(), p = (unsigned)1 << n;
    std::vector<std::vector<int>> subs;
    std::vector<int> sub;
    for (unsigned i = 0; i < p; ++i) {
      sub = {};
      for (unsigned j = 0; j < n; ++j) {
        if ((i >> j) & (unsigned)1)
          sub.push_back(nums[j]);
      }
      subs.push_back(sub);
    }
    return subs;
  }
};

class Solution3 {
private:
  static void recurse(std::vector<int> &nums, int i, std::vector<int> &subset,
                      std::vector<std::vector<int>> &powerSet) {
    powerSet.push_back(subset);
    for (int j = i; j < nums.size(); ++j) {
      subset.push_back(nums[j]);
      recurse(nums, j + 1, subset, powerSet);
      subset.pop_back();
    }
  }

public:
  // Runtime: 4 ms, faster than 98.26% of C++ online submissions for Subsets.
  // Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for
  // Subsets.
  //
  // recursive (backtracking)
  static std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> powerSet;
    std::vector<int> subset;
    recurse(nums, 0, subset, powerSet);
    return powerSet;
  }
};

int main() {
  std::vector<std::vector<int>> ans;
  std::vector<int> nums = {1, 2, 3};

  ans = Solution::subsets(nums);
  for (auto &s : ans) {
    printf("[");
    for (auto elem : s)
      printf("%d ", elem);
    printf("], ");
  }

  printf("\n");

  ans = Solution2::subsets(nums);
  for (auto &s : ans) {
    printf("[");
    for (auto elem : s)
      printf("%d ", elem);
    printf("], ");
  }

  printf("\n");

  ans = Solution3::subsets(nums);
  for (auto &s : ans) {
    printf("[");
    for (auto elem : s)
      printf("%d ", elem);
    printf("], ");
  }
}
