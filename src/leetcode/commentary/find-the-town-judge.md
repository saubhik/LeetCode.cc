# find-the-town-judge

The constraints of a problem are very important. `trust[i]` are all different. That means we have $O(n^{2})$ pairs. We need to store $\{j : j\ trusts\ i\}$ for each $i$. Then we check if the size of only one of these $i$ sets is $n-1$. If so, $i$ is what we want. Else, we return $-1$. 

We can reduce the storage further. Once, we find that $i$ is first element of a pair in `trust`, then we can remove the storage for $i$, as $i$ will never be a town judge.

We need a hash-map `unordered_map<int, vector<int>>`. We use `vector<int>` as our storage container for each $i$, since we are sure `trust[i]` are all different, and so we do not need the additional overhead of maintaining a `unorderd_set<int>`.

Not so fast! We can make use of the constraint $1 \leq N \leq 1000$, to use just the `vector<int>[N]` container. We can store $-1$ in the value for $i$, if $i$ is ruled out from consideration (when we encounter it as the first element of a pair).

Not so fast! We can store the counts of the second elements of each pair into a simple `int[]`. No need to store the information of identities of people trusting someone. We still need to rule someone out, if s/he comes as the first element in a pair.

We can also make the count of the first element in a pair, decremented by $1$ - but this would be useless operation, after the first time the element appears.