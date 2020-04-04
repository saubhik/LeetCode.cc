//
// Created by saubhik on 2020/04/04.
//
#include <vector>

class Solution {
public:
  // Runtime: 8 ms, faster than 99.11% of C++ online submissions for Maximize
  // Distance to Closest Person. Memory Usage: 7.9 MB, less than 100.00% of C++
  // online submissions for Maximize Distance to Closest Person.
  //
  // O(n) time, O(1) space.
  static int maxDistToClosest(std::vector<int> &seats) {
    int n = seats.size(), firstSeat = -1, lastSeat = -1, maxSeatDist = -1;
    for (int i = 0; i < n; ++i)
      if (seats[i]) {
        if (lastSeat > -1)
          maxSeatDist = std::max(maxSeatDist, i - lastSeat);
        else
          firstSeat = i;
        lastSeat = i;
      }
    return std::max(firstSeat, std::max(n - 1 - lastSeat, maxSeatDist / 2));
  }
};

int main() {
  std::vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
  assert(Solution::maxDistToClosest(seats) == 2);

  seats = {1, 0, 0, 0};
  assert(Solution::maxDistToClosest(seats) == 3);

  seats = {0, 0, 1, 0, 1, 1};
  assert(Solution::maxDistToClosest(seats) == 2);

  seats = {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
  assert(Solution::maxDistToClosest(seats) == 4);
}
