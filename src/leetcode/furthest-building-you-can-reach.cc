/*
 * Use ladders for the longest climbs, and bricks for the shorter ones.
 * We need to find the longest climbs encountered so far.
 * Maintain a min-heap with size equal to number of ladders.
 */
class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int, vector<int>, greater<int>> heap;
    int i, diff;

    for (i = 1; i < heights.size(); ++i) {
      diff = heights[i] - heights[i - 1];

      if (diff < 0) {
        continue;
      }

      if (heap.size() < ladders) {
        heap.push(diff);
      } else if (!heap.empty() && heap.top() < diff) {
        bricks -= heap.top();
        heap.pop();
        heap.push(diff);
      } else {
        bricks -= diff;
      }

      if (bricks < 0) {
        return i - 1;
      }
    }

    return i - 1;
  }
};
