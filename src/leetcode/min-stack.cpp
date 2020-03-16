//
// Created by saubhik on 2020/03/17.
//
#include <stack>

// Runtime: 24 ms, faster than 98.51% of C++ online submissions for Min Stack.
// Memory Usage: 15.8 MB, less than 100.00% of C++ online submissions for Min
// Stack.
// O(1) push, pop, top, getMin.
class MinStack {
private:
  std::stack<std::pair<int, int>> st;

public:
  /** initialize your data structure here. */
  MinStack() { st = {}; }

  void push(int x) {
    int tmp;
    if (st.empty() || x < (tmp = st.top().second))
      st.emplace(x, x);
    else
      st.emplace(x, tmp);
  }

  void pop() { st.pop(); }

  int top() { return st.top().first; }

  int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
  auto *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  assert(obj->getMin() == -3);
  obj->pop();
  assert(obj->top() == 0);
  assert(obj->getMin() == -2);
}
