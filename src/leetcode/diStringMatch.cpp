//
// Created by saubhik on 2019/10/30.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> diStringMatch(const string &S) {
        int left = 0, right = S.size(), i;
        vector<int> res(S.size() + 1);
        for (i = 0; i < (int) S.size(); ++i) res[i] = S[i] == 'I' ? left++ : right--;
        res[i] = left;
        return res;
    }
};

int main() {
    for (auto &i: Solution::diStringMatch("IDID")) cout << i << " ";
    cout << "\n";
    for (auto &i: Solution::diStringMatch("DDI")) cout << i << " ";
    cout << "\n";
    for (auto &i: Solution::diStringMatch("III")) cout << i << " ";
    cout << "\n";
    for (auto &i: Solution::diStringMatch("DDD")) cout << i << " ";
    cout << "\n";
}
