//
// Created by saubhik on 2020/03/28.
//
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  // Runtime: 124 ms, faster than 6.88% of C++ online submissions for Number of
  // Equivalent Domino Pairs. Memory Usage: 18.8 MB, less than 100.00% of C++
  // online submissions for Number of Equivalent Domino Pairs.
  //
  // O(n) time, O(n) space.
  static int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes) {
    std::unordered_map<std::string, int> ump;
    std::string domStr, domStrRev;
    for (auto &domino : dominoes) {
      domStr = std::to_string(domino[0]) + "," + std::to_string(domino[1]);
      domStrRev = std::to_string(domino[1]) + "," + std::to_string(domino[0]);
      if (ump.find(domStr) != ump.end())
        ++ump[domStr];
      else
        ++ump[domStrRev];
    }
    int count = 0;
    for (auto it = begin(ump); it != end(ump); ++it)
      count += (it->second) * (it->second - 1) / 2; // n choose 2
    return count;
  }
};

class Solution2 {
public:
  // Runtime: 48 ms, faster than 66.40% of C++ online submissions for Number of
  // Equivalent Domino Pairs. Memory Usage: 18.7 MB, less than 100.00% of C++
  // online submissions for Number of Equivalent Domino Pairs.
  //
  // let's use the constraints
  // 1 <= dominoes.length <= 40000 (we cannot do quadratic time)
  // 1 <= dominoes[i][j] <= 9
  // since C++ does not provide a hash for std::pair<int, int>, we will use
  // vector<int> with (9+8+...+1 = 9(10)/2 = 45) elements,
  // because (i, j) ~ (j, i).
  // first 9 elements being: (1,1),...,(1,9)
  // next 9 elements being:  (2,1),...,(2,9)
  // ...
  // last 9 elements being:  (9,1),...,(9,9).
  // Translation of (i,j) to int:
  // (1,1) -> 1  (9)
  // (2,2) -> 10 (8)
  // (2,3) -> 11
  // (2,9) -> 17
  // (3,3) -> 18 (7)
  // (3,9) -> 24
  // (4,4) -> 25 (6)
  // (5,5) -> 31 (5)
  //
  // (x,y) -> (1 + 45 - ((9 - x + 1) * (9 - x + 1 + 1) / 2)) + (y - x)
  // (3,9) -> (1 + 45 - 28 + 6) = 45 - 21 = 24.
  // Simplifying,
  // (x, y) -> 46 + y - x - (10 - x) * (11 - x) / 2
  // Check one more example:
  // (2, 3) -> 46 + 1 - 4 * 9 = 46 + 1 - 36 = 11.
  // To convert to 0-index:
  // (x, y) -> 45 + y - x - (10 - x) * (11 - x) / 2
  // (1, 1) -> 0.
  // Since, we do not iterate over std::unordered_map<string, int> like above,
  // this should bring the time complexity down.
  //
  // O(n) time, O(n) space.
  static int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes) {
    std::vector<int> counts(45, 0);
    int count = 0, index;

    for (auto &d : dominoes) {
      if (d[0] > d[1])
        std::swap(d[0], d[1]);
      index = 45 + d[1] - d[0] - ((10 - d[0]) * (11 - d[0])) / 2;
      ++counts[index];
      count += counts[index] - 1;
    }

    return count;
  }
};

class Solution3 {
public:
  // courtesy: Lee
  // Runtime: 56 ms, faster than 47.17% of C++ online submissions for Number of
  // Equivalent Domino Pairs. Memory Usage: 19.1 MB, less than 100.00% of C++
  // online submissions for Number of Equivalent Domino Pairs.
  //
  // Use clever custom hashing.
  static int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes) {
    std::unordered_map<int, int> count;
    int res = 0;
    for (auto &d : dominoes)
      res += count[std::min(d[0], d[1]) * 10 + std::max(d[0], d[1])]++;
    return res;
  }
};

int main() {
  std::vector<std::vector<int>> dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
  assert(Solution::numEquivDominoPairs(dominoes) == 1);
  assert(Solution2::numEquivDominoPairs(dominoes) == 1);
  assert(Solution3::numEquivDominoPairs(dominoes) == 1);

  dominoes = {{1, 2}, {3, 2}, {2, 1}, {1, 2}, {2, 3}, {2, 1}};
  assert(Solution::numEquivDominoPairs(dominoes) == 7);
  assert(Solution2::numEquivDominoPairs(dominoes) == 7);
  assert(Solution3::numEquivDominoPairs(dominoes) == 7);

  dominoes = {{2, 1}, {5, 4}, {3, 7}, {6, 2}, {4, 4}, {1, 8}, {9, 6}, {5, 3},
              {7, 4}, {1, 9}, {1, 1}, {6, 6}, {9, 6}, {1, 3}, {9, 7}, {4, 7},
              {5, 1}, {6, 5}, {1, 6}, {6, 1}, {1, 8}, {7, 2}, {2, 4}, {1, 6},
              {3, 1}, {3, 9}, {3, 7}, {9, 1}, {1, 9}, {8, 9}};
  assert(Solution::numEquivDominoPairs(dominoes) == 11);
  assert(Solution2::numEquivDominoPairs(dominoes) == 11);
  assert(Solution3::numEquivDominoPairs(dominoes) == 11);
}
