//
// Created by saubhik on 2020/05/05.
//
#include "iostream"
#include <vector>
using namespace std;

class Solution {
public:
  // This gets TLEd. This is O(n^2) time, O(1) space.
  static int findRadius(vector<int> &houses, vector<int> &heaters) {
    int minRad = INT_MIN;
    for (int &house : houses) {
      int minDiff = INT_MAX;
      for (int &heater : heaters) {
        minDiff = min(minDiff, abs(house - heater));
      }
      minRad = max(minRad, minDiff);
    }
    return minRad;
  }
};

class Solution2 {
public:
  // Runtime: 176 ms, faster than 14.01% of C++ online submissions for Heaters.
  // Memory Usage: 25.3 MB, less than 14.29% of C++ online submissions for
  // Heaters.
  //
  // This is O(n) time, O(1) space.
  static int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(begin(houses), end(houses));
    sort(begin(heaters), end(heaters));

    int minDiff = INT_MAX, minRad, closestHeater;

    for (int he = 0; he < heaters.size(); ++he) {
      if (abs(houses[0] - heaters[he]) < minDiff) {
        minDiff = abs(houses[0] - heaters[he]);
        closestHeater = he;
      } else {
        break;
      }
    }

    minRad = minDiff;

    for (int ho = 1; ho < houses.size(); ++ho) {
      minDiff = abs(houses[ho] - heaters[closestHeater]);
      for (int he = closestHeater + 1; he < heaters.size(); ++he) {
        if (abs(houses[ho] - heaters[he]) <= minDiff) {
          minDiff = abs(houses[ho] - heaters[he]);
          closestHeater = he;
        } else {
          break;
        }
      }
      minRad = max(minRad, minDiff);
    }

    return minRad;
  }
};

class Solution3 {
private:
  static int getMinDiff(vector<int> &arr, int elem) {
    // arr is sorted
    int left = 0, right = (int)arr.size() - 1;

    if (elem < arr[left]) {
      return arr[left] - elem;
    }

    if (elem > arr[right]) {
      return elem - arr[right];
    }

    int mid;
    while (right - left > 1) {
      mid = left + (right - left) / 2;
      if (arr[mid] < elem) {
        left = mid;
      } else if (arr[mid] > elem) {
        right = mid;
      } else {
        return 0;
      }
    }

    return min(arr[right] - elem, elem - arr[left]);
  }

public:
  // Runtime: 180 ms, faster than 12.46% of C++ online submissions for Heaters.
  // Memory Usage: 25.4 MB, less than 14.29% of C++ online submissions for
  // Heaters.
  //
  // use binary search for each house to get the min distance from a heater.
  static int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(begin(houses), end(houses));
    sort(begin(heaters), end(heaters));

    int minRad = INT_MIN;
    for (int house : houses) {
      minRad = max(minRad, getMinDiff(heaters, house));
    }

    return minRad;
  }
};

int main() {
  vector<int> houses = {0, 8, 9, 10, 15, 17, 60, 65, 90}, heaters = {2, 50, 85};
  assert(Solution::findRadius(houses, heaters) == 15);
  assert(Solution2::findRadius(houses, heaters) == 15);
  assert(Solution3::findRadius(houses, heaters) == 15);

  houses = {282475249, 622650073, 984943658, 144108930,
            470211272, 101027544, 457850878, 458777923},
  heaters = {823564440, 115438165, 784484492, 74243042,  114807987,
             137522503, 441282327, 16531729,  823378840, 143542612};
  assert(Solution2::findRadius(houses, heaters) == 161834419);
  assert(Solution3::findRadius(houses, heaters) == 161834419);

  houses = {1, 2, 3, 4, 5, 6, 7, 8, 3};
  heaters = {1, 2, 3, 4, 5, 6, 7, 8, 3};
  assert(Solution2::findRadius(houses, heaters) == 0);
  assert(Solution3::findRadius(houses, heaters) == 0);
}
