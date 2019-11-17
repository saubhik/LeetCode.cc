//
// Created by saubhik on 2019/11/16.
//
#include <iostream>
#include <map>
using namespace std;

long MOD = 1000000007;

long helper(map<pair<int, int>, long> &mp, pair<int, int> &pr) {
  int m = pr.first, n = pr.second;

  cout << "calling with " << m << " " << n << "\n";

  if (m < 0 || n < 0)
    return 0;

  if (mp.count(pr) > 0)
    return mp[pr];

  pair<int, int> pr1 = make_pair(m - 1, n - 2), pr2 = make_pair(m - 2, n - 1);
  mp[pr] = (helper(mp, pr1) % MOD + helper(mp, pr2) % MOD) % MOD;
  cout << "calling with " << m << " " << n << " " << mp[pr] << "\n";
  return mp[pr];
}

int main() {
  int x, y;
  cin >> x >> y;
  map<pair<int, int>, long> mp;
  pair<int, int> pr(x, y);
  mp.emplace(make_pair(0, 0), 1);
  cout << helper(mp, pr);
}