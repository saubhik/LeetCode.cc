class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        // How much we can do in each day?
        // 1. We can do j1 in day, and rest in d-1.
        // 2. We can do j1,j2 in day, and rest in d-1.
        // ...
        int n = jobDifficulty.size();
        vector<vector<int>> cache(d+1, vector<int>(n, -1));
        
        int minDifficulty = dfs(d, 0, jobDifficulty, cache);
        return minDifficulty == INT_MAX ? -1 : minDifficulty;
    }
    
    // O(nnd) time.
    // O(nd) space.
    int dfs(
        int day,
        int jobId,
        vector<int>& jobDifficulty, 
        vector<vector<int>>& cache)
    {
        int n = jobDifficulty.size();
        
        if (jobId == n && day == 0) { return 0; }
        if (jobId == n || day == 0) { return INT_MAX; }
        if (cache[day][jobId] != -1) { return cache[day][jobId]; }
        
        int ans = INT_MAX;
        int difficulty = INT_MIN;
        int tmp;
        
        for (int j = jobId; j < n; ++j) {
            difficulty = max(difficulty, jobDifficulty[j]);
            tmp = dfs(day-1, j+1, jobDifficulty, cache);
            if (tmp != INT_MAX) { ans = min(ans, difficulty + tmp); }
        }
        
        return cache[day][jobId] = ans;
    }
};
