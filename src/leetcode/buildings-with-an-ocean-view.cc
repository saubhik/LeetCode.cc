class Solution {
 public:
  vector<int> findBuildings(vector<int>& heights) {
    int n = heights.size(), maxSoFar = 0;
    vector<int> bs;
    for (int i = n - 1; i >= 0; --i) {
      if (heights[i] > maxSoFar) {
        maxSoFar = heights[i];
        bs.push_back(i);
      }
    }
    reverse(bs.begin(), bs.end());
    return bs;
  }
};
