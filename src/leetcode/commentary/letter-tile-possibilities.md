# Letter Tile Possibilities

Find the number of possible non-empty arrangements of $n$ items, where $m_1$ are of one kind, $m_2$ are of another kind, ..., $m_k$ are of another kind, and $m_1 + ... + m_k = n$.

There are $k$ different arrangements of $1$ item. 

We have $T(1) = k$.

<u>For $2$ items</u>, there are $k(k-1)$ ways of choosing $2$ different items, and $k'$ ways of choosing $2$ similar items, where $k_2' \leq k$ is the number of kinds which have at least $2$ items in their group. Call this $T(2)$.

We have $T(2)=k(k-1) + k_2'$.

<u>For $3$ items:</u>

**Case 1:** There are $k(k-1)(k-2)$ ways of choosing $3$ different items.

**Case 2:** $k_3' \leq k$ ways of choosing $3$ similar items, where $k_3'$ is the number of kinds which have at least $3$ items in their group.

**Case 3:** We want $2$ similar items. I can choose $2$ similar items in $k_{2}'$ ways, and the other one from $(k-1)$ remaining. I can put this other one amidst the $2$ similar ones, in $3$ ways.

We have $T(3)=k(k-1)(k-2) + 3 \cdot k_2'(k-1) + k_3'$.

<u>For 4 items</u>:

**Case 1:** All different: $k(k-1)(k-2)(k-3)$.

**Case 2:** 3 similar: $4 \cdot k_{3}'(k - 1)$.

**Case 3:** 2 similar: $3 \cdot k_{2}'(k - 1)(k - 2)$.

**Case 4:** 4 similar: $k_{4}'$.

$T(4) = k(k-1)(k-2)(k-3) + 4 \cdot k_{3}'(k - 1) + 6 \cdot k_{2}'(k - 1)(k - 2) + k_{4}'$.

$T(5) = k(k-1)(k-2)(k-3)(k-4) + 5 \cdot k_{4}'(k-1) + 10 \cdot k_{3}'(k-1)(k-2) + 10 \cdot k_{2}'(k-1)(k-2)(k-3) + k_{5}'$.

This line of reasoning continues till we have $k$ items. What about the case when we have $2$ similar items

For $k+1$ items, we need to have at least $1$ similar item. That similar item could be from any one of the $k$ groups, so $k$ ways of choosing the similar item.

---

## Re-take on Sunday, December 15, 2019

Thinking about a completely different way of solving it. This is very much like solving the "enumerating subsets" problem. We can solve it thinking about whether to include the element in considerating to our sequence in consideration or not. So this is a recursive solution.

```cpp
void enumerate(string& s, string &cand, int i, set<string>& seqs) {
  if (i == s.length())
    seqs.add(cand);
  
  enumerate(s, cand, i+1, seqs); // not including i
  enumerate(s, cand + s[i], i+1, seqs); // including i
}
```

Let's test this fast using a 2-element string `"AB"`. `enumerate("AB", "", 0, {})` is called. This calls `enumerate("AB", "", 1, {})`. This calls `enumerate("AB", "", 2, {})`. Now `seqs` gets updated from `{}` to `{""}`. Then `enumerate("AB", "B", 2, {""})` is called. Then `seqs` gets updated to `{"", "B"}`. Then `enumerate("AB", "A")`

```
e("", 0, {})
		-> e("", 1, {})
				-> e("", 2, {})
				-> e("B", 2, {""})
  	-> e("A", 1, {"", "B"})
  			-> e("A", 2, {"", "B"})
  			-> e("AB", 2, {"", "B", "A"})
```

Now, `seqs == {"", "B", "A", "AB"}`.

The time complexity is `O(2**n)` and space complexity is `O(n)`.