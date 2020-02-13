//
// Created by saubhik on 2020/02/13.
//
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 12 ms, faster than 93.51% of C++ online submissions for Find
  // Smallest Letter Greater Than Target. Memory Usage: 9 MB, less than 81.82%
  // of C++ online submissions for Find Smallest Letter Greater Than Target.
  //
  // O(n) time, O(1) space.
  static char nextGreatestLetter(vector<char> &letters, char target) {
    for (char letter : letters)
      if (letter > target)
        return letter;
    return letters[0];
  }
};

class Solution2 {
public:
  // Runtime: 12 ms, faster than 93.51% of C++ online submissions for Find
  // Smallest Letter Greater Than Target. Memory Usage: 9 MB, less than 72.73%
  // of C++ online submissions for Find Smallest Letter Greater Than Target.
  //
  // binary search
  // O(lgn) time, O(1) space.
  static char nextGreatestLetter(vector<char> &letters, char target) {
    int n = letters.size(), lo = 0, hi = n - 1, mid;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2;
      if (letters[mid] > target)
        hi = mid;
      else
        lo = mid + 1;
    }
    return letters[hi] <= target ? letters[(hi + 1) % n] : letters[hi];
  }
};

int main() {
  vector<char> letters = {'c', 'f', 'j'};
  printf("%c %c\n", Solution::nextGreatestLetter(letters, 'a'),
         Solution2::nextGreatestLetter(letters, 'a'));
  printf("%c %c\n", Solution::nextGreatestLetter(letters, 'k'),
         Solution2::nextGreatestLetter(letters, 'k'));
  printf("%c %c\n", Solution::nextGreatestLetter(letters, 'j'),
         Solution2::nextGreatestLetter(letters, 'j'));
  printf("%c %c", Solution::nextGreatestLetter(letters, 'd'),
         Solution2::nextGreatestLetter(letters, 'd'));
}