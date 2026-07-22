class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = (int)piles.size(); 
        vector<vector<int>> dp(n, vector<int>(n, 0)); 

        // 1. Base cases: single pile ranges
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i]; 
        }

        // 2. Process subproblems by length (from length 2 to n)
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1; // Right boundary
                
                dp[i][j] = max(piles[i] - dp[i + 1][j], 
                               piles[j] - dp[i][j - 1]); 
            }
        }

        // 3. Final result for full array [0 ... n-1]
        return dp[0][n - 1] > 0; 
    }
};