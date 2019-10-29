//
// Created by saubhik on 2019/10/29.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // binary search, O(log n)
    static int peakIndexInMountainArray(vector<int> &A) {
        unsigned lo = 0, hi = A.size() - 1, mid = 0;
        while (lo < hi) {
            mid = hi - (hi - lo) / 2;
            if ((mid == hi || A[mid] < A[mid + 1]) && (mid == lo || A[mid - 1] < A[mid])) lo = mid;
            else hi = mid;
        }
        return (int) mid;
    }
};

int main() {
    int arr[] = {0, 5, 7, 9, 3, 2};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    // expected: 3
    cout << Solution::peakIndexInMountainArray(vec);
}
