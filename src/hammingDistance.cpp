//
// Created by saubhik on 2019/10/27.
//
#include <iostream>

using namespace std;

int lookup[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

class Solution {

public:
    int hammingDistance(int x, int y) {
        return (int) countSetBits6((unsigned int) x ^ (unsigned int) y);
    }

private:
    // method 1
    static unsigned int countSetBits1(unsigned int num) {
        // calculate the Hamming Weight
        // time: O(log n)
        unsigned int count = 0;
        while (num) {
            count += num & (unsigned) 1;
            num = num >> (unsigned) 1;
        }
        return count;
    }

    // method 2
    // just recursive implementation of method 1
    static unsigned int countSetBits2(unsigned int num) {
        if (num == 0) return 0;
        return (num & 1) + countSetBits2(num >> 1);
    }

    // method 3
    // Brian Kernighan's approach
    // (n - 1) flips all bits after (& including) the rightmost set bit.
    // (n & (n - 1)) is 0 for all bits after (& including) the rightmost set bit.
    // (n & (n - 1)) unsets the rightmost 1.
    // the number of loops is the number of set bits in n.
    static unsigned int countSetBits3(unsigned int num) {
        unsigned count = 0;
        while (num) {
            num &= num - 1;
            count++;
        }
        return count;
    }

    // method 4
    // Recursive solution to Brian Kernighan's approach.
    static unsigned int countSetBits4(unsigned int num) {
        if (num == 0) return 0;
        return 1 + countSetBits4(num & (num - 1));

    }

    // method 5
    // using __builtin_popcount()
    // It is a built in function of GCC not C++.
    // This function uses CPU specific instructions, which is faster.
    static unsigned int countSetBits5(unsigned int num) {
        return __builtin_popcount(num);
    }

    // method 6
    // pre-compute & store values for nibbles in a map/array.
    // time: O(log n)
    static unsigned int countSetBits6(unsigned int num) {
        if (num == 0) return 0;
        return lookup[(num & (unsigned) 15)] + countSetBits6(num >> (unsigned) 4);
    }
};

int main() {
    Solution obj;
    // expected: 2
    cout << obj.hammingDistance(1, 4);
}
