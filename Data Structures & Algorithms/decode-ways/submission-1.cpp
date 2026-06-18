class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(); 
        if (n == 0 || s[0] == '0') return 0;

        // Expand size to n+1 to safely accommodate the dp[i+2] check
        vector<int> dp(n + 1, 0); 
        
        // Base Cases
        dp[n] = 1; // Base ground truth: 1 valid way to decode an empty terminal string
        dp[n-1] = (s[n-1] != '0') ? 1 : 0; 

        // Start from n-2 since n-1 and n are already locked down
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0; // Leading zeros make this branch invalid
            } else {
                int d1 = s[i] - '0'; 
                int d2 = s[i+1] - '0'; 
                int combined = d1 * 10 + d2;

                // If it's a valid 2-digit jump (10 to 26)
                if (combined <= 26) {
                    dp[i] = dp[i+1] + dp[i+2]; //Fixed: proper combinatorial branching
                } else {
                    dp[i] = dp[i+1]; // Only single-digit decoding is valid
                }
            }
        }

        return dp[0]; 
    }
};