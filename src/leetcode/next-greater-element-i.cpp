//
// Created by saubhik on 2019/11/21.
//
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // 61.79% run-time, 73.68% memory
  // O(n^2) time, O(n) space.
  static vector<int> nextGreaterElement(vector<int> &nums1,
                                        vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    unordered_map<int, int> ump;

    for (int i = 0; i < n2; ++i)
      for (int k = i + 1; k < n2; ++k)
        if (nums2[k] > nums2[i]) {
          ump[nums2[i]] = nums2[k];
          break;
        }

    for (int i = 0; i < n1; ++i)
      if (ump.count(nums1[i]))
        nums1[i] = ump[nums1[i]];
      else
        nums1[i] = -1;

    return nums1;
  }
};

class Solution2 {
public:
  // 97.19% run-time, 68.42% memory
  // O(n) time, O(n) space.
  static vector<int> nextGreaterElement(vector<int> &nums1,
                                        vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();
    unordered_map<int, int> ump;

    stack<int> s;
    for (int num : nums2) {
      while (s.size() && s.top() < num) {
        ump[s.top()] = num;
        s.pop();
      }
      s.push(num);
    }

    for (int i = 0; i < n1; ++i) {
      auto it = ump.find(nums1[i]);
      if (it != ump.end())
        nums1[i] = ump[nums1[i]];
      else
        nums1[i] = -1;
    }

    return nums1;
  }
};

int main() {
  vector<int> ans, nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};
  ans = Solution2::nextGreaterElement(nums1, nums2);
  for (auto num : ans)
    printf("%d ", num);

  printf("\n");

  nums1 = {2, 4}, nums2 = {1, 2, 3, 4};
  ans = Solution2::nextGreaterElement(nums1, nums2);
  for (auto num : ans)
    printf("%d ", num);
}
