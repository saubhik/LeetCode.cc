//
// Created by saubhik on 2020/03/09.
//
#include <unordered_map>
#include <vector>

class Solution {
private:
  static void permuteRec(std::vector<int> &nums,
                         std::vector<std::vector<int>> &permutations,
                         std::vector<int> &tmp,
                         std::unordered_map<int, bool> &used) {

    if (tmp.size() == nums.size())
      permutations.push_back(tmp);

    for (int i = 0; i < nums.size(); ++i) {
      if (!used[nums[i]]) {
        tmp.push_back(nums[i]);
        used[nums[i]] = true;
        permuteRec(nums, permutations, tmp, used);
        tmp.pop_back();
        used[nums[i]] = false;
      }
    }
  }

public:
  // Runtime: 8 ms, faster than 98.48% of C++ online submissions for
  // Permutations. Memory Usage: 8.7 MB, less than 100.00% of C++ online
  // submissions for Permutations.
  //
  // Recursion with backtracking.
  // Idea is similar to subsets.
  // O(n!) time, O(n) space.
  static std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> permutations = {};
    std::vector<int> tmp = {};
    std::unordered_map<int, bool> used;
    permuteRec(nums, permutations, tmp, used);
    return permutations;
  }
};

class Solution2 {
private:
  static void permuteRec(std::vector<int> &nums, int begin,
                         std::vector<std::vector<int>> &permutations) {
    if (begin == nums.size())
      permutations.push_back(nums);

    for (int i = begin; i < nums.size(); ++i) {
      std::swap(nums[begin], nums[i]);
      permuteRec(nums, begin + 1, permutations);
      std::swap(nums[begin], nums[i]);
    }
  }

public:
  // courtesy: xiaohui7
  // Runtime: 8 ms, faster than 98.48% of C++ online submissions for
  // Permutations. Memory Usage: 8.2 MB, less than 100.00% of C++ online
  // submissions for Permutations.
  //
  // This is much more space efficient than previous solution (usual
  // backtracking).
  static std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> permutations;
    permuteRec(nums, 0, permutations);
    return permutations;
  }
};

int main() {
  std::vector<int> nums = {1, 2, 3};
  std::vector<std::vector<int>> perms = Solution::permute(nums);
  for (auto &row : perms) {
    for (auto &elem : row)
      printf("%d ", elem);
    printf("\n");
  }
  printf("\n");
  perms = Solution2::permute(nums);
  for (auto &row : perms) {
    for (auto &elem : row)
      printf("%d ", elem);
    printf("\n");
  }
}