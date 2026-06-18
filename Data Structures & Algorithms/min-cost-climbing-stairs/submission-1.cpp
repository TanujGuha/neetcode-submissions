class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ; 
        vector <int> dp(n+1 , INT_MAX) ; 
        dp[n] = 0 ; 
        dp[n-1] = cost[n-1] ; 
        dp[n-2] = cost[n-2] ; 

        for (int j = n-3 ; j >= 0 ; j--)
        {
            dp[j] = min(dp[j+1] , dp[j+2]) + cost[j] ; 
        }

        return min(dp[0] ,dp[1]) ; 
    }
};
