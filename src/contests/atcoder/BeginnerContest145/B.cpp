//
// Created by saubhik on 2019/11/16.
//
#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  if (N % 2 != 0) {
    cout << "No";
    return 0;
  }
  int mid = N / 2;
  for (int i = 0; i < mid; ++i) {
    if (S[i] != S[i + mid]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}