class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = accumulate(nums.begin() , nums.end() , 0) ; 
        if (abs(target) > tot || (tot + target)&1) return 0 ; 

        int t = (tot + target)/2 ;
        vector <int> dp(t + 1 , 0) ; 
        dp[0] = 1 ; 

        for (auto num : nums)
        {
            for (int s = t ; s >= num ; s--)
            {
                dp[s] +=dp[s-num] ;
            }
        }

        return dp[t] ; 
    }
};
