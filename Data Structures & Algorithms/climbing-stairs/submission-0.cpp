class Solution {
public:
    int climbStairs(int n) {
        vector <int> dp(n+1) ; 
        dp[0] = 1 ; 
        dp[1] = 1 ; 

        for (int j = 2 ; j <= n ; j++)
        {
            dp[j] = dp[j-1] + dp[j-2] ;
        }


        return dp[n] ; 
    }
};
