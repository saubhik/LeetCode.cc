//
// Created by saubhik on 2020/01/18.
//
#include <vector>

using namespace std;

class Solution {
public:
    // Runtime: 16 ms, faster than 99.91% of C++ online submissions for Group the People Given the Group Size They Belong To.
    // Memory Usage: 12.2 MB, less than 100.00% of C++ online submissions for Group the People Given the Group Size They Belong To.
    //
    // O(n) time, O(n) space.
    static vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> mp(n + 1), ans;
        vector<int> group;
        for (int i = 0; i < n; ++i)
            mp[groupSizes[i]].push_back(i);
        for (int i = 0; i < mp.size(); ++i)
            for (int j = 0; j < mp[i].size(); ++j) {
                if (j % i == 0) group = {};
                group.push_back(mp[i][j]);
                if (j % i == i - 1)
                    ans.push_back(group);
            }
        return ans;
    }
};

int main() {
    vector<int> groupSizes;
    vector<vector<int>> ans;

    groupSizes = {3, 3, 3, 3, 3, 1, 3};
    ans = Solution::groupThePeople(groupSizes);
    for (auto &group : ans) {
        for (int ind : group)
            printf("%d ", ind);
        printf("\n");
    }

    printf("\n");

    groupSizes = {2, 1, 3, 3, 3, 2};
    ans = Solution::groupThePeople(groupSizes);
    for (auto &group : ans) {
        for (int ind : group)
            printf("%d ", ind);
        printf("\n");
    }

    printf("\n");

    groupSizes = {1};
    ans = Solution::groupThePeople(groupSizes);
    for (auto &group : ans) {
        for (int ind : group)
            printf("%d ", ind);
        printf("\n");
    }
}

