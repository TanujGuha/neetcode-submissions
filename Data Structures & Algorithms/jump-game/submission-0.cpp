class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ; 

        vector <int> dp(n , 0 ) ; 
        dp[n-1] = 1 ; 
        for (int i = n-2 ; i >= 0 ; i--)
        {
            int mj = nums[i] ; 
            if (n - i - 1 <= mj)
            {
                dp[i] = 1 ; 
                continue ; 
            }

            for(int jl = 1 ; jl <= mj ; jl++)
            {
                if (dp[i + jl] == 1)
                {
                    dp[i] = 1 ; 
                    break ; 
                }
            }


        }
        if (dp[0] == 1)
        {
            return true ; 
        }
        else
        {
            return false ; 
        }
    }
};
