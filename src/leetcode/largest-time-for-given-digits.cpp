//
// Created by saubhik on 2020/05/24.
//
#include <functional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest
  // Time for Given Digits. Memory Usage: 9.5 MB, less than 10.00% of C++ online
  // submissions for Largest Time for Given Digits.
  //
  // using greedy here does not work. Example: [0, 6, 2, 6]
  // if the constraints look very very small, like here, please use brute force
  // O(1) time, O(1) space.
  static string largestTimeFromDigits(vector<int> &A) {
    int hours, mins, ans = -1, i, j, k, l;
    for (i = 0; i < 4; ++i) {
      for (j = 0; j < 4; ++j) {
        if (j != i) {
          for (k = 0; k < 4; ++k) {
            if (k != j && k != i) {
              l = 6 - i - j - k;
              hours = 10 * A[i] + A[j];
              mins = 10 * A[k] + A[l];
              if (hours < 24 && mins < 60) {
                ans = max(ans, hours * 60 + mins);
              }
            }
          }
        }
      }
    }
    if (ans == -1) {
      return "";
    }
    // is there way to do the following better?
    // this could be another way: to use to_string:
    // string res="";
    // if(ans/60<10) res+="0";
    // res+=to_string(ans/60);
    // res+=":";
    // if(ans%60<10) res+="0";
    // res+=to_string(ans%60);
    ostringstream oss;
    hours = ans / 60;
    mins = ans % 60;
    if (hours < 10) {
      oss << "0" << hours;
    } else {
      oss << hours;
    }
    oss << ":";
    if (mins < 10) {
      oss << "0" << mins;
    } else {
      oss << mins;
    }
    return oss.str();
  }
};

class Solution2 {
public:
  // fantastic use of prev_permutation with descending lexicographical sort
  static string largestTimeFromDigits(vector<int> &A) {
    sort(begin(A), end(A), greater<>());
    do {
      string hours = {(char)(A[0] + '0'), (char)(A[1] + '0')};
      string mins = {(char)(A[2] + '0'), (char)(A[3] + '0')};
      if (stoi(hours) < 24 && stoi(mins) < 60) {
        return hours + ":" + mins;
      }
    } while (prev_permutation(begin(A), end(A)));
    return "";
  }
};

int main() {
  vector<int> A;

  A = {1, 2, 3, 4};
  assert(Solution::largestTimeFromDigits(A) == "23:41");
  assert(Solution2::largestTimeFromDigits(A) == "23:41");

  A = {5, 5, 5, 5};
  assert(Solution::largestTimeFromDigits(A).empty());
  assert(Solution2::largestTimeFromDigits(A).empty());

  A = {0, 0, 1, 0};
  assert(Solution::largestTimeFromDigits(A) == "10:00");
  assert(Solution2::largestTimeFromDigits(A) == "10:00");

  A = {0, 0, 0, 2};
  assert(Solution::largestTimeFromDigits(A) == "20:00");
  assert(Solution2::largestTimeFromDigits(A) == "20:00");

  A = {0, 0, 3, 0};
  assert(Solution::largestTimeFromDigits(A) == "03:00");
  assert(Solution2::largestTimeFromDigits(A) == "03:00");
}