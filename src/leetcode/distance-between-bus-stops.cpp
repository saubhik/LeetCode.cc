//
// Created by saubhik on 2019/12/05.
//
#include <vector>
using namespace std;

class Solution {
public:
  // 95.66% run-time, 100% memory.
  // O(n) time, O(1) additional space.
  // Tried to remove % operations, but did not help much.
  static int distanceBetweenBusStops(vector<int> &distance, int start,
                                     int destination) {
    int i, n = distance.size(), clockDist = 0, antiClockDist = 0;
    for (i = start; i != destination;) {
      clockDist += distance[i];

      ++i;
      if (i == n)
        i = 0;
    }
    for (i = destination; i != start;) {
      antiClockDist += distance[i];
      if (antiClockDist > clockDist)
        return clockDist;

      ++i;
      if (i == n)
        i = 0;
    }
    return antiClockDist;
  }
};

int main() {
  // Example 1
  vector<int> distance = {1, 2, 3, 4};
  printf("%d\n", Solution::distanceBetweenBusStops(distance, 0, 1));

  // Example 2
  printf("%d\n", Solution::distanceBetweenBusStops(distance, 0, 2));

  // Example 3
  printf("%d", Solution::distanceBetweenBusStops(distance, 0, 3));
}
