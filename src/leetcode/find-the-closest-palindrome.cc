class Solution {
 public:
  string nearestPalindromic(string n) {
    int sz = n.length();

    if (sz == 1) {
      return string(1, n[0] - 1);
    }

    vector<long> candidates{
        (long)pow(10, sz) - 1,      // 97 -> 99
        (long)pow(10, sz - 1) - 1,  // 1001 -> 999
        (long)pow(10, sz) + 1,      // 999 -> 1001
        (long)pow(10, sz - 1) + 1   // 103 -> 101
    };

    long prefix = stol(n.substr(0, (sz + 1) / 2));
    vector<long> toFlip = {prefix - 1, prefix, prefix + 1};
    for (long f : toFlip) {
      string rev = to_string(f);
      if (sz % 2) {
        rev.pop_back();  // no need to reverse middle element
      }
      reverse(rev.begin(), rev.end());
      candidates.push_back(stol(to_string(f) + rev));
    }

    sort(candidates.begin(), candidates.end());

    long ans;
    long val = stol(n);
    long minDiff = INT_MAX;

    for (long candidate : candidates) {
      long diff = abs(val - candidate);
      if (diff > 0 && diff < minDiff) {
        minDiff = diff;
        ans = candidate;
      }
    }

    return to_string(ans);
  }
};
