//
// Created by saubhik on 2019/11/23.
//
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  // 64.40% run-time, 85.71% memory
  // O(|words|) time, O(|max_word|) additional space.
  static string toGoatLatin(string S) {
    istringstream ss(S);
    string word, ans, as;
    bool giveSpace = false;
    while (ss >> word) {
      ans += giveSpace ? " " : "";
      giveSpace = true;

      if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' ||
          word[0] == 'o' || word[0] == 'u' || word[0] == 'A' ||
          word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U')
        ans += word + "ma";
      else
        ans += word.substr(1) + word[0] + "ma";

      as += "a";
      ans += as;
    }
    return ans;
  }
};

class Solution2 {
public:
  // courtesy: claytonjwong
  // 100% run-time, 100% memory
  static string toGoatLatin(string S, string s = "", string a = "a",
                            ostringstream os = ostringstream()) {
    for (stringstream is(S); is >> s; a.push_back('a'))
      os << (s.substr(0, 1).find_first_of("aeiouAEIOU") ? s.substr(1) + s[0]
                                                        : s)
         << "ma" << a << (is.tellg() > 0 ? " " : "");
    return os.str();
  }
};

class Solution3 {
private:
  static bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  // courtesy: lzl124631x
  // 100% run-time, 100% memory
  static string toGoatLatin(string S) {
    istringstream ss(S);
    string word, ans, as = "a";
    while (ss >> word) {
      if (!isVowel(word[0]))
        rotate(word.begin(), word.begin() + 1, word.end());
      ans += (as.size() > 1 ? " " : "") + word + "ma" + as;
      as += "a";
    }
    return ans;
  }
};

int main() {
  puts(Solution3::toGoatLatin("I speak Goat Latin").c_str());
  puts(Solution3::toGoatLatin("The quick brown fox jumped over the lazy dog")
           .c_str());
}
