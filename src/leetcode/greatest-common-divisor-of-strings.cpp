//
// Created by saubhik on 2019/12/11.
//
#include <string>
using namespace std;

class Solution {
private:
  static int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }

public:
  // 92.90% run-time, 100% memory.
  static string gcdOfStrings(string str1, string str2) {
    int m = gcd(str1.length(), str2.length());
    for (int i = 1; i <= m; ++i) {
      if (m % i == 0) {
        int n = m / i;
        string sub1 = str1.substr(0, n), sub2 = str2.substr(0, n);
        if (sub1 != sub2)
          continue;
        else {
          bool found = true;

          for (int j = n; j + n <= str1.length(); j += n)
            if (str1.substr(j, n) != sub1) {
              found = false;
              break;
            }

          if (!found)
            continue;

          for (int j = n; j + n <= str2.length(); j += n)
            if (str2.substr(j, n) != sub2) {
              found = false;
              break;
            }

          if (!found)
            continue;

          return sub1;
        }
      }
    }
    return "";
  }
};

int main() {
  printf("%s\n", Solution::gcdOfStrings("ABCABC", "ABC").c_str());
  printf("%s\n", Solution::gcdOfStrings("ABABAB", "ABAB").c_str());
  printf("%s\n", Solution::gcdOfStrings("LEET", "CODE").c_str());
  printf("%s",
         Solution::gcdOfStrings("TAUXXTAUXXTAUXXTAUXXTAUXX",
                                "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX")
             .c_str());
}
