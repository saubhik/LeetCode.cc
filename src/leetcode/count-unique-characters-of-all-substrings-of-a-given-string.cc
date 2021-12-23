class Solution {
public:
  int uniqueLetterString(string s) {
    // Think for each letter, how many substrings are there
    // which has this unique letter. Contribution of points
    // by each index.
    //
    // Another example:
    // "ABA" -> A, B, A, AB, BA, ABA -> 8
    //  012
    // Points contributed by A at index 0: (0-(-1))*(2-0) = 2
    // Points contributed by B at index 1: (1-(-1))*(3-1) = 4
    // Points contributed by A at index 2: (3-2)*(2-0) = 2
    // Answer = 2+4+2 = 8
    //
    // We need the following metadata:
    // index 0: A (-1,0,2)
    // index 1: B (-1,1,3)
    // index 2: A (0,2,3)
    //
    // We can compute total points contributed by each index
    // later on when we encounter the same letter again.
    //
    // For each uppercase letter, we can store two integers.
    // A: -1,0 [curr=1, tot=0] -> 0,2 [curr=2, tot=2] -> 2,3 [curr=1, tot=4] 
    // B: -1,1 [curr=2, tot=0] -> 1,3 [curr=2, tot=4]
    //
    // curr is updated when partially computing contribution for an index.
    // curr is added to tot when contribution computated.
    // We can make tot cumulative.
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)

    int n = s.length();
    int tot = 0;
    int meta[26][2];
    memset(meta, -1, sizeof(meta));

    for (int i = 0; i < n; ++i) {
        int indx = s[i]-'A';
        tot += (meta[indx][1] - meta[indx][0]) * (i - meta[indx][1]);
        meta[indx][0] = meta[indx][1];
        meta[indx][1] = i;
    }

    for (int i = 0; i < 26; ++i) {
        tot += (meta[i][1] - meta[i][0]) * (n - meta[i][1]);
    }

    return tot;
  }
};
