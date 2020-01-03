//
// Created by saubhik on 2020/01/03.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 48 ms, faster than 95.51% of C++ online submissions for Replace
  // Elements with Greatest Element on Right Side. Memory Usage: 10.7 MB, less
  // than 100.00% of C++ online submissions for Replace Elements with Greatest
  // Element on Right Side.
  // O(n) time, O(1) space.
  static vector<int> replaceElements(vector<int> &arr) {
    int n = arr.size(), maxRight = -1, tmp;
    for (int i = n - 1; i >= 0; --i)
      arr[i] = exchange(maxRight, max(maxRight, arr[i]));
    return arr;
  }
};

int main() {
  vector<int> arr = {17, 18, 5, 4, 6, 1}, ans;
  ans = Solution::replaceElements(arr);
  for (int num : ans)
    printf("%d ", num);
}
