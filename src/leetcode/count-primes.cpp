//
// Created by saubhik on 2020/05/06.
//
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  // Runtime: 192 ms, faster than 35.27% of C++ online submissions for Count
  // Primes. Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions
  // for Count Primes.
  //
  // sieving, nearly O(n) time, O(n) space.
  static int countPrimes(int n) {
    if (n <= 1)
      return 0;

    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    int count = 0;

    for (int i = 2; i < n; ++i) {
      if (isPrime[i]) {
        ++count;
        for (int j = 2; j * i < n; ++j) {
          isPrime[j * i] = false;
        }
      }
    }
    return count;
  }
};

int main() {
  assert(Solution::countPrimes(10) == 4);
  assert(Solution::countPrimes(4) == 2);
}
