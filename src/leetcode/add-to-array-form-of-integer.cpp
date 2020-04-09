//
// Created by saubhik on 2020/04/07.
//
#include <iostream>
#include <vector>

class Solution {
public:
  // Runtime: 120 ms, faster than 36.20% of C++ online submissions for Add to
  // Array-Form of Integer. Memory Usage: 11.6 MB, less than 100.00% of C++
  // online submissions for Add to Array-Form of Integer.
  //
  // Seems like removing the `std::` and with this:
  // auto speedup=[](){
  //    std::ios::sync_with_stdio(false);
  //    std::cin.tie(nullptr);
  //    std::cout.tie(nullptr);
  //    return nullptr;
  // }();
  // I get the following:
  // Runtime: 104 ms, faster than 97.59% of C++ online submissions for Add to
  // Array-Form of Integer. Memory Usage: 11.6 MB, less than 100.00% of C++
  // online submissions for Add to Array-Form of Integer.
  //
  // O(n) time, O(1) space.
  static std::vector<int> addToArrayForm(std::vector<int> &A, int K) {
    int n = A.size(), carry = K, tmp;
    std::vector<int> ans;
    for (int i = n - 1; i >= 0 || carry > 0; --i) {
      tmp = i >= 0 ? A[i] + carry : carry;
      carry = tmp / 10;
      ans.push_back(tmp % 10);
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};

auto speedup = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution2 {
public:
  // Runtime: 112 ms, faster than 73.54% of C++ online submissions for Add to
  // Array-Form of Integer. Memory Usage: 10.2 MB, less than 100.00% of C++
  // online submissions for Add to Array-Form of Integer.
  //
  // courtesy: Lee
  // O(n) time, O(1) space
  static std::vector<int> addToArrayForm(std::vector<int> &A, int K) {
    for (int i = (int)A.size() - 1; i >= 0 && K > 0; --i) {
      A[i] += K;
      K = A[i] / 10;
      A[i] %= 10;
    }
    while (K > 0) {
      A.insert(A.begin(), K % 10);
      K /= 10;
    }
    return A;
  }
};

int main() {
  std::vector<int> A, x;

  A = {1, 2, 0, 0}, x = {1, 2, 3, 4};
  assert(Solution::addToArrayForm(A, 34) == x);
  assert(Solution2::addToArrayForm(A, 34) == x);

  A = {2, 7, 4}, x = {4, 5, 5};
  assert(Solution::addToArrayForm(A, 181) == x);
  assert(Solution2::addToArrayForm(A, 181) == x);

  A = {2, 1, 5}, x = {1, 0, 2, 1};
  assert(Solution::addToArrayForm(A, 806) == x);
  assert(Solution2::addToArrayForm(A, 806) == x);

  A = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9}, x = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  assert(Solution::addToArrayForm(A, 1) == x);
  assert(Solution2::addToArrayForm(A, 1) == x);
}
