//
// Created by saubhik on 2019/10/27.
//
#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.14159265

using namespace std;

int main() {
    long double a, b, x;
    cin >> a >> b >> x;
    if (2 * x <= (a * a * b)) {
        cout << setprecision(12) << 90.0 - (atan(2 * x / (a * b * b)) * 180 / PI);
    } else {
        cout << setprecision(12) << atan(2 * (a * a * b - x) / (a * a * a)) * 180 / PI;
    }
}