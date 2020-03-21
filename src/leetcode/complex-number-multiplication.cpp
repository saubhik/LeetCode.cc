//
// Created by saubhik on 2020/03/21.
//
#include <sstream>
#include <string>

class Solution {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complex
  // Number Multiplication. Memory Usage: 6.2 MB, less than 100.00% of C++
  // online submissions for Complex Number Multiplication.
  static std::string complexNumberMultiply(const std::string a, std::string b) {
    int pos1A = a.find('+'), pos2A = a.find('i');
    int p = std::stoi(a.substr(0, pos1A));
    int q = std::stoi(a.substr(pos1A + 1, pos2A));
    int pos1B = b.find('+'), pos2B = b.find('i');
    int r = std::stoi(b.substr(0, pos1B));
    int s = std::stoi(b.substr(pos1B + 1, pos2B));
    return std::to_string(p * r - q * s) + "+" + std::to_string(p * s + r * q) +
           "i";
  }
};

class Solution2 {
public:
  // Runtime: 0 ms, faster than 100.00% of C++ online submissions for Complex
  // Number Multiplication. Memory Usage: 6 MB, less than 100.00% of C++ online
  // submissions for Complex Number Multiplication.
  //
  // using stringstream
  static std::string complexNumberMultiply(std::string a, std::string b) {
    int ra, ia, rb, ib;
    char buff;
    std::stringstream aa(a), bb(b), ans;
    aa >> ra >> buff >> ia >> buff;
    bb >> rb >> buff >> ib >> buff;
    ans << ra * rb - ia * ib << "+" << ra * ib + rb * ia << "i";
    return ans.str();
  }
};

int main() {
  assert(Solution::complexNumberMultiply("1+1i", "1+1i") == "0+2i");
  assert(Solution2::complexNumberMultiply("1+1i", "1+1i") == "0+2i");
  assert(Solution::complexNumberMultiply("1+-1i", "1+-1i") == "0+-2i");
  assert(Solution2::complexNumberMultiply("1+-1i", "1+-1i") == "0+-2i");
}
