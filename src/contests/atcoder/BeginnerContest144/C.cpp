//
// Created by saubhik on 2019/10/27.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned long long n, i;
    cin >> n;
    unsigned long long divOne = 1, divTwo = n;
    for (i = floor(sqrt(n)); i > 0; i--) {
        if (n % i == 0) {
            divOne = i;
            divTwo = n / divOne;
            break;
        }
    }
    cout << (divOne - 1) + (divTwo - 1);
}
