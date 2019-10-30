//
// Created by saubhik on 2019/10/30.
//

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> counter;

    RecentCounter() = default;

    int ping(int t) {
        int lo = max(t - 3000, 0), hi = t, count = 0;
        counter.push(t);
        while (counter.front() < t - 3000) counter.pop();
        return counter.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
int main() {
    auto *obj = new RecentCounter;
    cout << obj->ping(1) << obj->ping(100) << obj->ping(3001) << obj->ping(3002);
}

