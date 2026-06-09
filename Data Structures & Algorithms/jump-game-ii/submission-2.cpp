class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ; 


        vector <int> dp(n , INT_MAX) ; 
        dp[n-1] = 0 ; 


        for(int i = n-2 ; i >= 0 ; i--)
        {
            int mj = nums[i] ; 
            if (n - i - 1 <= mj)
            {
                dp[i] = 1 ; 
            }

            else
            {
                int mi = INT_MAX ; 
                for (int jl = 1 ; jl <= mj ; jl++)
                {
                    if (i + jl >= n)
                    {
                        break ; 
                    }
                    mi = min(mi , dp[i + jl]) ; 
                }

                if (mi != INT_MAX)
                {
                    dp[i] = mi + 1 ; 
                }
            }
        }


        return dp[0] ; 
    }
};
