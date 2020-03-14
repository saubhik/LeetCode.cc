# 830. Positions of Large Groups

Consider `abbxxxxzzy`, then the output is `[[3,6]]`. We want the starting and ending positions of every large group. So, we will store these into a `vector<vector<int>>`. Once the size is more than the current maximum, we will flush our vector, and enter the new one.