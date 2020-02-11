# power-of-three

Check whether an integer is a power of three.

<u>Approach 1: Loop iteration</u>

```c++
class Solution {
 public:
  // O(log_{3}{n}) time, O(1) space.
 	bool isPowerOfThree(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) n /= 3;
    return n == 1;
  }
};
```

<u>Approach 2: Base conversion</u>

If we convert to base 3, then we should only have a single leading 1 followed by 0s.

We need to convert integer to base 3. Is there any C++ method to do that?

```c++
class Solution {
  public:
  	bool isPowerOfThree(int n) {
    	pass 
    }
};
```

