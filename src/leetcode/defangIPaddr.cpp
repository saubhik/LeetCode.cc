//
// Created by saubhik on 2019/10/26.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static string defangIPaddr(string address) {
        string res;
        for (char ch : address) {
            if (ch == '.') {
                res += "[.]";
            } else {
                res += ch;
            }
        }
        return res;
    }
};

int main() {
    cout << Solution::defangIPaddr("1.1.1.1");
}
