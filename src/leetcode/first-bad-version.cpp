// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <iostream>

class Solution {
private:
  static bool isBadVersion(int version) { return version >= 4; }

public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad
  // Version. Memory Usage: 6 MB, less than 100.00% of C++ online submissions
  // for First Bad Version.
  //
  // using binary search, O(lgn) time.
  static int firstBadVersion(int n) {
    int first = 1, last = n, mid;
    while (first != last) {
      mid = first + (last - first) / 2;
      if (isBadVersion(mid))
        last = mid;
      else
        first = mid + 1;
    }
    return first;
  }
};

int main() { assert(Solution::firstBadVersion(5) == 4); }