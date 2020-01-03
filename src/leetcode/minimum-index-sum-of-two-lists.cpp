//
// Created by saubhik on 2020/01/03.
//
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  // Runtime: 92 ms, faster than 97.95% of C++ online submissions for Minimum
  // Index Sum of Two Lists. Memory Usage: 28.1 MB, less than 88.89% of C++
  // online submissions for Minimum Index Sum of Two Lists. O(n1+n2) time, O(n1)
  // space.
  static vector<string> findRestaurant(vector<string> &list1,
                                       vector<string> &list2) {
    unordered_map<string, int> counts;
    int n1 = list1.size(), n2 = list2.size();
    vector<string> ans;

    for (int i = 0; i < n1; ++i)
      counts[list1[i]] = i;

    int minCount = INT_MAX;
    for (int j = 0; j < n2; ++j)
      if (counts.find(list2[j]) != counts.end()) {
        counts[list2[j]] += j;
        if (counts[list2[j]] < minCount)
          ans = {list2[j]}, minCount = counts[list2[j]];
        else if (counts[list2[j]] == minCount)
          ans.push_back(list2[j]);
      }

    return ans;
  }
};

int main() {
  vector<string> list1, list2, ans;
  list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse",
           "Shogun"};
  ans = Solution::findRestaurant(list1, list2);
  for (auto s : ans)
    printf("%s ", s.c_str());

  printf("\n");

  list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  list2 = {"KFC", "Shogun", "Burger King"};
  ans = Solution::findRestaurant(list1, list2);
  for (auto s : ans)
    printf("%s ", s.c_str());
}
