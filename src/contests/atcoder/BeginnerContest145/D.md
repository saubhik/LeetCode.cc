# Knight

Deep diving into [ABC 145, Problem D](https://atcoder.jp/contests/abc145/tasks/abc145_d).

In one step, the knight can go to $(x+1, y+2)$ or $(x+2,y+1)$ from $(x,y)$. Suppose knight takes $m$ steps of first type and $n$ steps of second type. Then, we have the following system:
$$
m + 2n = x\\
2m + n = y
$$
Solving, we get, $m + n = (x + y)/3$ and $m = y - (x+y)/3$ and $n = x - (x+y)/3$. It's necessary to have $(x+y)\mod3=0$, to assure existence of integer solutions. Once, we get $m$ and $n$, the total number of ways is all arrangements of $m+n$ things where $m$ are like kind, and $n$ are another like kind. We need to compute ${m+n}\choose{m}$. We need to give the answer $\mod 10^{9}+7$.

We will go through the best `C++` solution. I will use [forar](https://atcoder.jp/users/forar)'s [solution](https://atcoder.jp/contests/abc145/submissions/8473324), with `Exec Time` of $1ms$, and `Memory` of $128KB$, both best in class. Amazing!

I will show the entire source here first, and then we will research into the details:

```c++
#include <cstdio>

template<int N, typename T, T M>
struct factorial_mod
{
	T mod[N + 1];
	T inv_mod[N + 1];

	constexpr factorial_mod() : mod(), inv_mod()
	{
		mod[0] = 1;
		for (int i = 0; i < N; ++i)
		{
			mod[i + 1] = (mod[i] * (i + 1)) % M;
		}
		inv_mod[N] = power(mod[N], M - 2);
		for (int i = N - 1; i >= 0; --i)
		{
			inv_mod[i] = (inv_mod[i + 1] * (i + 1)) % M;
		}
	}

	constexpr T power(T a, T b) const
	{
		T r = 1;
		while (b > 0)
		{
			if ((b & 1) != 0) r = (r * a) % M;
			a = (a * a) % M;
			b >>= 1;
		}
		return r;
	}

	constexpr T comb(T n, T r) const
	{
		if (r < 0 || r > n || n < 0) return 0;
		return (((mod[n] * inv_mod[r]) % M) * inv_mod[n - r]) % M;
	}
};

constexpr factorial_mod<1000000, long long, 1000000007> fmod;

int main()
{
  long long x, y;
  scanf("%lld%lld", &x, &y);
  if ((x + y) % 3 != 0)
  {
    puts("0");
    return 0;
  }
  long long n = (x + y) / 3;
  x -= n;
  y -= n;
  if (x < 0 || y < 0)
  {
    puts("0");
    return 0;
  }
  printf("%lld\n", fmod.comb(n, x));
  return 0;
}
```



Reading the `main()`, I notice the following:

* Declaring `x` and `y` as `long long`. Is that needed given the problem bounds $1≤X≤10^6$,  $1≤Y≤10^6$?
* Using `puts("0")` instead of `printf()`. `puts()` takes C string, and appends a newline character (`'\n'`) at the end automatically. So, it's faster to type.
* Takes care of the edge cases nicely.
  * Case when $(x+y) \mod 3 \neq 0$, prints $0$.
  * Case when $m<0$ or $n<0$, prints $0$.
* Uses `return 0;` for every exit point.

Now, I will try to understand the `fmod.comb(n, x)` part.