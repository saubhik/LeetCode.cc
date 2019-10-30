//
// Created by saubhik on 2019/10/30.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static int minDeletionSize(vector<string> &A) {
        int n = A[0].size(), w = A.size(), count = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 1; j < w; ++j) {
                if (A[j][i] < A[j - 1][i]) {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    // expected: 3
    vector<string> vec = {"zyx", "wvu", "tsr"};
    cout << Solution::minDeletionSize(vec) << "\n";
    // expected: 0
    vec = {"a", "b"};
    cout << Solution::minDeletionSize(vec) << "\n";
    // expected: 1
    vec = {"cba", "daf", "ghi"};
    cout << Solution::minDeletionSize(vec);
}
