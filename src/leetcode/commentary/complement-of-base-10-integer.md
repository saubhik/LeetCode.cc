# Complement of base 10 integer

Consider $5$. The binary representation is $101$. I want to get $010$. It is trivial to solve it in $log_{2}(n)$ time. Non-trivial problem is: can I do it using bit operations?

I did solve a similar problem before where we find the not of a numbler, `~x`. But I do not remember it.

Let me remember a trick I committed to memory. Something about $n\&(n-1)$. If we do that here, we get `101 & 100 = 100`. Playing with more cases: `10100 & 10011 = 10000`. So $n-1$ just sets all $0$s below the least significant set bit to $1$ and unsets the least significant set bit. Higher bits are equal. So  when you $\&$ it, the least significant set bit gets unset. But that will not help here.

What I need here, is to get the number `1...1101` from `0...0101`. Then the answer is just the complement of the previous number.

What if I just `xor` it the maximum number, with all set bits. `1...111 ^ 0...101 = 1...010`. But this has so many set bits in the front. What if I `or` it with the maximum number. `1...111 | 0...101 = 1...101`. Now I can take the complement.

What is the maximum number? It is just `~0`. It is `-1`? So the answer is `~(-1 | n)`. No it does not work as expected. There is some trouble with negative numbers and `~`. Can I do it without `~`?

```c++
unsigned mask = ~0;
while (n & mask) mask <<= 1;
// our answer is ~mask ^ n;
```

This trick makes `mask == 1...1000`. Now I can take the complement to get `0...0111`. And then `xor` with `0...0101`. I will get the complement. This is exactly what I forgot. To remember for the next time, I need to understand that I need to shift the max number to the left, till all relevant positions are filled with 0.

If $n==0$, then this will not work. So, we can do the following, to ensure at least one loop run:

```c++
unsigned mask = ~0;
do 
  mask <<= 1;
while (n & mask);
// our answer is ~mask ^ n;
```

