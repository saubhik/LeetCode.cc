##### group-the-people-given-the-group-size-they-belong-to

There are $n$ people whose IDs go from `0` to `n-1` and each person belongs to **exactly** one group. Given the array `groupSizes` of length `n` telling the group size each person belongs to, return the groups there are and the people's IDs each group includes.

**Example 1**: `groupSizes=[3,3,3,3,3,1,3]`. This means the person with `id=0` belongs to group of size `3`, and so does people with `id`s `1, 2, 3, 5`. Let's fill the groups in a greedy way, since any answer is acceptable. Let's assign:

```
Group 1 = [0,1,2]
Group 2 = [3,4,6]
Group 3 = [5]
```

**Example 2**: `groupSizes=[2,1,3,3,3,2]`. Let's assign:

```
Group 1 = [0,5]
Group 2 = [1]
Group 3 = [2,3,4]
```

If the groupSize changes, the create a new group. Best to use a hash map with the size as the index. If the container is empty, create a new group. Else, check if the last group's size matches with the index, if not append, else create a new group.

Another way is to put the values in the hash map, and then when building the answer we can divide the values.

Let's try to run this on `[2,1,3,3,3,2,2,2]`.

```
[0,5]
[1]
[2,3,4]
[6,7]
```

I do want to avoid the `vector<vector<vector<int>>>` structure.