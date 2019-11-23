//
// Created by saubhik on 2019/11/23.
//
#include <numeric>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 96.78% run-time, 100% memory
  // O(n) time, O(n) space
  static int calPoints(vector<string> &ops) {
    stack<int> points;
    for (auto s : ops) {
      if (s == "+") {
        int top1 = points.top();
        points.pop();
        int top2 = points.top();
        points.push(top1);
        points.push(top1 + top2);
      } else if (s == "D") {
        points.push(2 * points.top());
      } else if (s == "C") {
        points.pop();
      } else {
        points.push(stoi(s));
      }
    }

    int sum = 0;
    while (!points.empty()) {
      sum += points.top();
      points.pop();
    }

    return sum;
  }
};

int main() {
  vector<string> ops = {"5", "2", "C", "D", "+"};
  printf("%d\n", Solution::calPoints(ops)); // 30

  ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  printf("%d\n", Solution::calPoints(ops)); // 27
}
