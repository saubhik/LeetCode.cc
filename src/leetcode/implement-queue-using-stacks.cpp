// This is not so good than the below one.
class MyQueue1 {
private:
    stack<int> s1, s2;
public:
    MyQueue1() {}
    
    // Invariant: s1.empty() && !s2.empty()
    // O(n) time.
    void push(int x) {
        // Pour s2 to s1.
        while (!s2.empty()) s1.push(s2.top()), s2.pop();
        s1.push(x);
        // Pour s1 to s2.
        while (!s1.empty()) s2.push(s1.top()), s1.pop();
    }
    
    // O(1) time.
    int pop() {
        auto x = s2.top();
        s2.pop();
        return x;
    }
    
    // O(1) time.
    int peek() {
        return s2.top();
    }
    
    // O(1) time.
    bool empty() {
        return s2.empty(); 
    }
};

class MyQueue {
private:
    stack<int> s1, s2;
    int s1_front;
public:
    MyQueue() {}
    
    // O(1) time.
    void push(int x) {
        if (s1.empty()) s1_front = x;
        s1.push(x);
    }

    // Amortized O(1) time.
    // After n pops, we incur cost of O(n) time, otherwise O(1) time.
    // For n pops, we incur (n-1) O(1) cost, and 1 O(n) cost = O(n/n) = O(1) amortized cost.
    //
    // Invariant: s2 contains reversed numbers.
    // Use s2 for peek/pop. Use s1 for push.
    //
    // init: [] [3,2,1]
    // push(4): [4] [3,2,1]
    // push(5): [4,5] [3,2,1]
    // pop(): [4,5] [3,2,1]
    int pop() {
        if (!s2.empty()) { 
            auto x = s2.top(); 
            s2.pop(); 
            return x;
        }

        // nothing in s2. rebalance.
        while (!s1.empty()) {
            s2.push(s1.top()); 
            s1.pop();
        }

        // something in s2 guaranteed.
        auto x = s2.top();
        s2.pop();
        return x;
    }

    // O(1) time.
    int peek() {
        if (!s2.empty()) return s2.top();
        // nothing in s2. something must be in s1.
        // we could rebalance, but since this is always a valid call, use s1_front hack.
        return s1_front;
    }

    // O(1) time.
    bool empty() {
        return s1.empty() && s2.empty();
    }
};