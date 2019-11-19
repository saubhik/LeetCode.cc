//
// Created by saubhik on 2019/11/19.
//
#include <bitset>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  // 6.62% run-time, 33.33% memory
  static int distributeCandies(vector<int> &candies) {
    set<int> st(begin(candies), end(candies));
    return min(st.size(), candies.size() / 2);
  }
};

class Solution2 {
public:
  // 43.07% run-time, 66.67% memory
  static int distributeCandies(vector<int> &candies) {
    set<int> st;
    for (int candy : candies) {
      st.insert(candy);
      if (st.size() == candies.size() / 2)
        return st.size();
    }
    return st.size();
  }
};

class Solution3 {
public:
  // 88.86% run-time, 66.67% memory
  static int distributeCandies(vector<int> &candies) {
    unordered_set<int> st;
    for (int candy : candies) {
      st.insert(candy);
      if (st.size() == candies.size() / 2)
        return st.size();
    }
    return st.size();
  }
};

class Solution4 {
public:
  // 98.52% run-time, 100% memory
  static int distributeCandies(vector<int> &candies) {
    bitset<200001> bs;
    int j = 0;
    for (auto c : candies) {
      if (!bs.test(100000 + c)) {
        bs.set(100000 + c);
        ++j;
      }
      if (j == candies.size() / 2)
        return j;
    }
    return j;
  }
};

class Solution5 {
public:
  // 97.97% run-time, 100% memory
  static int distributeCandies(vector<int> &candies) {
    bitset<200001> hash;
    for (int c : candies)
      hash.set(100000 + c);
    return min(hash.count(), candies.size() / 2);
  }
};

int main() {
  vector<int> candies = {1, 1, 2, 2, 3, 3};
  printf("%d\n", Solution::distributeCandies(candies));
  printf("%d\n", Solution2::distributeCandies(candies));
  printf("%d\n", Solution3::distributeCandies(candies));
  printf("%d\n", Solution4::distributeCandies(candies));
  printf("%d\n", Solution5::distributeCandies(candies));

  candies = {1, 1, 2, 3};
  printf("%d\n", Solution::distributeCandies(candies));
  printf("%d\n", Solution2::distributeCandies(candies));
  printf("%d\n", Solution3::distributeCandies(candies));
  printf("%d\n", Solution4::distributeCandies(candies));
  printf("%d", Solution5::distributeCandies(candies));
}
