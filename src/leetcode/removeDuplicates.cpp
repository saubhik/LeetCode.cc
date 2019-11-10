//
// Created by saubhik on 2019/11/10.
//
#include <stack>
#include <string>
using namespace std;

class Solution1 {
public:
  // 16% run-time, 100% memory
  static string removeDuplicates(string S) {
    bool duplicateFound = true;
    while (duplicateFound) {
      duplicateFound = false;
      size_t i = 1;
      for (; i < S.size(); ++i)
        if (S[i] == S[i - 1]) {
          S.erase(i - 1, 2);
          duplicateFound = true;
          break;
        }
    }
    return S;
  }
};

class Solution2 {
public:
  // 26.87% run-time, 100% memory
  static string removeDuplicates(string S) {
    for (size_t i = 1; i < S.length(); ++i) {
      if (i > 0 && S[i] == S[i - 1]) {
        S.erase(i - 1, 2);
        i -= 2;
      }
    }
    return S;
  }
};

class Solution3 {
public:
  // Two pointer technique
  // 91.29% run-time, 100% memory
  static string removeDuplicates(string S) {
    size_t newPtr = 0;
    for (size_t oldPtr = 0; oldPtr < S.length(); ++oldPtr) {
      S[newPtr] = S[oldPtr];
      if (newPtr > 0 && S[newPtr] == S[newPtr - 1])
        --newPtr;
      else
        ++newPtr;
    }
    return S.substr(0, newPtr);
  }
};

class Solution4 {
public:
  // C++ strings can be used as stack
  // 91.29% run-time, 100% memory
  static string removeDuplicates(const string &S) {
    string ans;
    for (char ch : S) {
      if (!ans.empty() && ans.back() == ch)
        ans.pop_back();
      else
        ans.push_back(ch);
    }
    return ans;
  }
};

int main() {
  printf("%s\n", Solution1::removeDuplicates("abbaca").c_str());
  printf("%s\n", Solution2::removeDuplicates("abbaca").c_str());
  printf("%s\n", Solution3::removeDuplicates("abbaca").c_str());
  printf("%s\n", Solution4::removeDuplicates("abbaca").c_str());

  printf("%s\n", Solution1::removeDuplicates("bba").c_str());
  printf("%s\n", Solution2::removeDuplicates("bba").c_str());
  printf("%s\n", Solution3::removeDuplicates("bba").c_str());
  printf("%s", Solution4::removeDuplicates("bba").c_str());
}