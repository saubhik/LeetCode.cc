//
// Created by saubhik on 2019/12/13.
//
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
private:
  static void floodFillRec(vector<vector<int>> &image, int sr, int sc,
                           int newColor, vector<vector<bool>> &visited) {
    visited[sr][sc] = true;

    if (sr < image.size() && (sc - 1) >= 0 &&
        image[sr][sc - 1] == image[sr][sc] && !visited[sr][sc - 1])
      floodFillRec(image, sr, sc - 1, newColor, visited);

    if (sr < image.size() && (sc + 1) < image[0].size() &&
        image[sr][sc + 1] == image[sr][sc] && !visited[sr][sc + 1])
      floodFillRec(image, sr, sc + 1, newColor, visited);

    if ((sr - 1) >= 0 && sc < image[0].size() &&
        image[sr - 1][sc] == image[sr][sc] && !visited[sr - 1][sc])
      floodFillRec(image, sr - 1, sc, newColor, visited);

    if ((sr + 1) < image.size() && sc < image[0].size() &&
        image[sr + 1][sc] == image[sr][sc] && !visited[sr + 1][sc])
      floodFillRec(image, sr + 1, sc, newColor, visited);

    image[sr][sc] = newColor;
  }

public:
  // 96.54% run-time (20ms), 77.78% memory (10.3MB).
  // DFS.
  // O(mn) time, O(m + n) space.
  static vector<vector<int>> floodFill(vector<vector<int>> &image, int sr,
                                       int sc, int newColor) {
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size()));
    floodFillRec(image, sr, sc, newColor, visited);
    return image;
  }
};

class Solution2 {
public:
  // 96.54% run-time (20ms), 11.11% memory (10.8MB).
  // DFS.
  // O(mn) time, O(m + n) space.
  static vector<vector<int>> floodFill(vector<vector<int>> &image, int sr,
                                       int sc, int newColor) {

    if (image[sr][sc] == newColor)
      return image;

    int origColor = image[sr][sc];
    image[sr][sc] = newColor;

    if ((sc - 1) >= 0 && image[sr][sc - 1] == origColor)
      floodFill(image, sr, sc - 1, newColor);

    if ((sc + 1) < image[0].size() && image[sr][sc + 1] == origColor)
      floodFill(image, sr, sc + 1, newColor);

    if ((sr - 1) >= 0 && image[sr - 1][sc] == origColor)
      floodFill(image, sr - 1, sc, newColor);

    if ((sr + 1) < image.size() && image[sr + 1][sc] == origColor)
      floodFill(image, sr + 1, sc, newColor);

    return image;
  }
};

int main() {
  vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}, ans;
  ans = Solution2::floodFill(image, 1, 1, 2);
  for (auto row : ans) {
    for (auto num : row)
      printf("%d ", num);
    printf("\n");
  }

  printf("\n");

  image = {{0, 0, 0}, {0, 1, 1}};
  ans = Solution2::floodFill(image, 1, 1, 1);
  for (auto row : ans) {
    for (auto num : row)
      printf("%d ", num);
    printf("\n");
  }
}
