//
// Created by saubhik on 2019/11/16.
//
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x[N], y[N];
  for (int i = 0; i < N; ++i)
    cin >> x[i] >> y[i];

  double ans = 0;
  for (int i = 0; i < N; ++i)
    for (int j = i + 1; j < N; ++j)
      ans +=
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));

  cout << setprecision(12) << (ans * 2 / N);
}