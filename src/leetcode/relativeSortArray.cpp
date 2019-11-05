//
// Created by saubhik on 2019/11/05.
//
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  // O(n) time, store frequencies in table
  static vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> freq(1001), res;
    for (int num : arr1)
      freq[num]++;

    // first place the arr2 elements
    for (int num : arr2)
      while (freq[num]-- > 0)
        res.push_back(num);

    // place the remaining arr1 elements
    for (int i = 0; i < (int)freq.size(); ++i)
      while (freq[i]-- > 0)
        res.push_back(i);

    return res;
  }
};

int main() {
  // Output: [2,2,2,1,4,3,3,9,6,7,19]
  vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19},
              arr2 = {2, 1, 4, 3, 9, 6}, vec;
  vec = Solution::relativeSortArray(arr1, arr2);
  for (int num : vec)
    printf("%d ", num);
}
