//
// Created by saubhik on 2019/10/27.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (n == i * j) {
                cout << "Yes";
                return 0;
            }
    cout << "No";
}
