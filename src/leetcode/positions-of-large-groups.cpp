//
// Created by saubhik on 2020/01/16.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // O(n) time, O(1) space.
    static vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        int n = S.size(), st = 0, en = 0;
        for (int i = 1; i < n; ++i) {
            if (S[i] != S[i - 1]) {
                en = i - 1;
                if (en - st + 1 >= 3) {
                    if (ans.empty())
                        ans = {{st, en}};
                    else
                        ans.push_back({st, en});
                }
                st = i;
            }
        }
        if (en - st + 1 >= 3) // all characters same
            ans = {{0, en}};
        return ans;
    }
};

int main() {
    vector<vector<int>> ans;

    ans = Solution::largeGroupPositions("abbxxxxzzy");
    for (auto vec : ans)
        printf("[%d, %d] ", vec[0], vec[1]);

    printf("\n");

    ans = Solution::largeGroupPositions("abc");
    for (auto vec : ans)
        printf("[%d, %d] ", vec[0], vec[1]);

    printf("\n");

    ans = Solution::largeGroupPositions("abcdddeeeeaabbbcd");
    for (auto vec : ans)
        printf("[%d, %d] ", vec[0], vec[1]);

    printf("\n");

    ans = Solution::largeGroupPositions("aaa");
    for (auto vec : ans)
        printf("[%d, %d] ", vec[0], vec[1]);

    printf("\n");

    ans = Solution::largeGroupPositions("a");
    for (auto vec : ans)
        printf("[%d, %d] ", vec[0], vec[1]);
}