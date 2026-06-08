class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size() ; 

        int s = 0 ; 
        for(int i = 0  ; i < n  ; i++)
        {
            s += nums[i] ; 
        }

        if (s%2 != 0)
        {
            return false ; 
        }

        vector <vector <bool>> dp(n+1 , vector<bool> (s/2 + 1 ,false )) ; 

        for (int i = 0 ; i <= n ; i++)
        {
            dp[i][0] = true; 
        }

        for (int i = 1 ; i <= n ; i++)
        {
            dp[i][nums[i-1]] = true ; 
        }

        for (int i = 1 ; i <= n ; i++)
        {
            for(int j = 0 ; j < s/2+1 ; j++)
            {
                dp[i][j] = dp[i-1][j] ; 
                if (j >= nums[i-1])
                {
                    dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]] ;
                }
                
            } 
        }


        return dp[n][s/2]  ; 
    }
};
