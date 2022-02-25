/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
 public:
  // 0,0,0,0
  // 0,0,1,1
  // 0,0,0,1
  // 0,1,1,1
  // check all rows of a single column.
  // binary search over columns.
  // O(mlogn) time.
  int leftMostColumnWithOneAlternative(BinaryMatrix &binaryMatrix) {
    int rows = binaryMatrix.dimensions()[0];
    int cols = binaryMatrix.dimensions()[1];

    int leftCol = 0;
    int rightCol = cols - 1;

    if (!isZeroCol(rows, leftCol, binaryMatrix)) return leftCol;
    if (isZeroCol(rows, rightCol, binaryMatrix)) return -1;

    // Invariants:
    // isZeroColumn(leftCol) == true
    // isZeroColumn(rightCol) == false

    while (rightCol - leftCol > 1) {
      int midCol = leftCol + (rightCol - leftCol) / 2;
      if (isZeroCol(rows, midCol, binaryMatrix))
        leftCol = midCol;
      else
        rightCol = midCol;
    }
    return rightCol;
  }

  // O(m+n) time.
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    int rows = binaryMatrix.dimensions()[0];
    int cols = binaryMatrix.dimensions()[1];

    // Start from top right.
    // Go left if entry is 1.
    // Go down if entry is 0.
    int i = 0;
    int j = cols - 1;
    while (i < rows && j >= 0) {
      if (binaryMatrix.get(i, j) == 1)
        --j;
      else
        ++i;
    }
    return j == cols - 1 ? -1 : j + 1;
  }

 private:
  bool isZeroCol(int rows, int col, BinaryMatrix &binaryMatrix) {
    for (int i = 0; i < rows; ++i) {
      if (binaryMatrix.get(i, col) == 1) {
        return false;
      }
    }
    return true;
  }
};
