class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> dp(n); 
        if (n == 1)
        {
            return nums[n-1] ; 
        }
        dp[n-1] = nums[n-1] ; 
        dp[n-2] = max(nums[n-1] , nums[n-2]) ; 

        for (int j = n-3 ; j >= 0; j--)
        {
            dp[j] = max(nums[j] + dp[j+2] , dp[j+1]) ; 
        } 

        return dp[0] ; 
    }
};
