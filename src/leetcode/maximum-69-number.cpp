//
// Created by saubhik on 2020/01/27.
//
#include <string>
using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69
  // Number. Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions
  // for Maximum 69 Number. O(log_{10}(n)) time, O(1) space.
  static int maximum69Number(int num) {
    bool notChanged = true;
    string numStr = to_string(num);
    for (char &i : numStr)
      if (i == '6') {
        i = '9';
        break;
      }
    return stoi(numStr);
  }
};

int main() {
  printf("%d\n", Solution::maximum69Number(9669));
  printf("%d\n", Solution::maximum69Number(9996));
  printf("%d\n", Solution::maximum69Number(9999));
}
