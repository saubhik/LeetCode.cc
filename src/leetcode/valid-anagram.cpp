//
// Created by saubhik on 2019/12/08.
//
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  // 8.02% run-time, 5.97% memory
  // O(n) time, O(n) space.
  static bool isAnagram(string s, string t) {
    unordered_multiset<char> ums;
    for (auto ch : s)
      ums.insert(ch);
    for (auto ch : t) {
      auto it = ums.find(ch);
      if (it != ums.end())
        ums.erase(it);
      else
        return false;
    }
    return ums.empty();
  }
};

class Solution2 {
public:
  // 98.48% run-time, 83.58% memory.
  // O(n) time, O(1) space.
  static bool isAnagram(string s, string t) {
    int mp[26] = {};
    for (auto ch : s)
      ++mp[ch - 'a'];
    for (auto ch : t) {
      --mp[ch - 'a'];
      if (mp[ch - 'a'] < 0)
        return false;
    }

    for (auto i : mp)
      if (i != 0)
        return false;

    return true;
  }
};

int main() {
  printf("%d %d\n", Solution::isAnagram("anagram", "nagaram"),
         Solution2::isAnagram("anagram", "nagaram"));
  printf("%d %d\n", Solution::isAnagram("rat", "car"),
         Solution2::isAnagram("rat", "car"));
}
