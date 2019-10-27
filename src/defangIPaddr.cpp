//
// Created by saubhik on 2019/10/26.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
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
    Solution obj;
    cout << obj.defangIPaddr("1.1.1.1");
}
