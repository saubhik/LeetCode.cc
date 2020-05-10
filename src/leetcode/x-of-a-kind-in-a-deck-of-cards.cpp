//
// Created by saubhik on 2020/05/10.
//
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  static int gcd(int m, int n) {
    if (m == 0) {
      return n;
    }
    if (m > n) {
      return gcd(m % n, n);
    } else {
      return gcd(n % m, m);
    }
  }

public:
  // Runtime: 36 ms, faster than 22.11% of C++ online submissions for X of a
  // Kind in a Deck of Cards. Memory Usage: 17.5 MB, less than 8.33% of C++
  // online submissions for X of a Kind in a Deck of Cards.
  //
  // O(n) time, O(n) space.
  static bool hasGroupsSizeX(vector<int> &deck) {
    int res = -1;
    unordered_map<int, int> ump;
    for (int &val : deck) {
      ++ump[val];
    }
    // cout << "counts: ";
    for (auto it = begin(ump); it != end(ump); ++it) {
      if (it->second < 2) {
        return false;
      } else {
        res = res == -1 ? it->second : gcd(it->second, res);
      }
      // cout << it->second << " ";
    }
    // cout << "\n" << res << "\n";
    return res > 1;
  }
};

class Solution2 {
private:
  static int gcd(int m, int n) {
    if (m == 0) {
      return n;
    } else if (n == 0) {
      return m;
    }
    if (m > n) {
      return gcd(m % n, n);
    } else {
      return gcd(n % m, m);
    }
  }

public:
  // Runtime: 32 ms, faster than 30.82% of C++ online submissions for X of a
  // Kind in a Deck of Cards. Memory Usage: 17.6 MB, less than 8.33% of C++
  // online submissions for X of a Kind in a Deck of Cards.
  static bool hasGroupsSizeX(vector<int> &deck) {
    std::ios::sync_with_stdio(false);
    int arr[10001] = {0};
    for (int item : deck) {
      ++arr[item];
    }
    for (int i = 1; i < 1001; ++i) {
      if (arr[i] != arr[i - 1] && gcd(arr[i - 1], arr[i]) == 1) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  vector<int> deck;

  deck = {1, 2, 3, 4, 4, 3, 2, 1};
  assert(Solution::hasGroupsSizeX(deck));

  deck = {1, 1, 1, 2, 2, 2, 3, 3};
  assert(!Solution::hasGroupsSizeX(deck));

  deck = {1};
  assert(!Solution::hasGroupsSizeX(deck));

  deck = {1, 1};
  assert(Solution::hasGroupsSizeX(deck));

  deck = {1, 1, 2, 2, 2, 2};
  assert(Solution::hasGroupsSizeX(deck));

  deck = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
  assert(Solution::hasGroupsSizeX(deck));

  deck = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3};
  assert(!Solution::hasGroupsSizeX(deck));
}
