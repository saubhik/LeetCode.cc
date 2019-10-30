//
// Created by saubhik on 2019/10/30.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // O(n log n) time, O(1) space
    static int arrayPairSum(vector<int> &nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int) nums.size(); ++i) if (i % 2 == 0) sum += nums[i];
        return sum;
    }
};

int main() {
    vector<int> input = {1, 4, 3, 2};
    cout << Solution::arrayPairSum(input);
}
