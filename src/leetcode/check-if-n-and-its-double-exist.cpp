//
// Created by saubhik on 2020/05/23.
//
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 8 ms, faster than 87.46% of C++ online submissions for Check If N
  // and Its Double Exist. Memory Usage: 9.9 MB, less than 100.00% of C++ online
  // submissions for Check If N and Its Double Exist.
  //
  // O(n) time, O(2000) space.
  // Another way could be sort and then binary search.
  static bool checkIfExist(vector<int> &arr) {
    bool posStore[1001] = {false};
    bool negStore[1001] = {false};
    short zeroCount = 0;

    for (int num : arr) {
      if (num == 0) {
        ++zeroCount;
      } else if (num > 0) {
        posStore[num] = true;
      } else {
        negStore[-num] = true;
      }
    }

    for (int num : arr) {
      if (num == 0) {
        if (zeroCount > 1) {
          return true;
        }
      } else if (num > 0) {
        if ((num / 2) * 2 == num) {
          if (posStore[num / 2]) {
            return true;
          }
          if (num * 2 < 1001 && posStore[num * 2]) {
            return true;
          }
        }
      } else {
        if ((num / 2) * 2 == num) {
          if (negStore[-num / 2]) {
            return true;
          }
          if (-num * 2 < 1001 && negStore[-num * 2]) {
            return true;
          }
        }
      }
    }

    return false;
  }
};

int main() {
  vector<int> arr;

  arr = {10, 2, 5, 3};
  assert(Solution::checkIfExist(arr));

  arr = {7, 1, 14, 11};
  assert(Solution::checkIfExist(arr));

  arr = {3, 1, 7, 11};
  assert(!Solution::checkIfExist(arr));

  arr = {0};
  assert(!Solution::checkIfExist(arr));

  arr = {0, 0};
  assert(Solution::checkIfExist(arr));

  arr = {-16, -13, 8};
  assert(!Solution::checkIfExist(arr));

  arr = {16, -16, 8};
  assert(Solution::checkIfExist(arr));
}