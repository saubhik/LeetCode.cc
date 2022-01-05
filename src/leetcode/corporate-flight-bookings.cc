/*
 Range Caching:
 For each booking (firsti, lasti, seatsi), do the following:
  seats[firsti] += seatsi;
  seats[lasti] -= seatsi;
 Then, return the prefix sum array.
*/

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> seats(n, 0);

    for (const vector<int>& booking : bookings) {
      seats[booking[0] - 1] += booking[2];
      if (booking[1] < n) {
        seats[booking[1]] -= booking[2];
      }
    }

    for (int i = 1; i < n; ++i) {
      seats[i] += seats[i - 1];
    }

    return seats;
  }
};
