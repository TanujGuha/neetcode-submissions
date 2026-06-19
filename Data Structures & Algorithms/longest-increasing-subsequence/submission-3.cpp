class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ; 
        vector <int> dp(n+1, 1);
        dp[1] = 1 ; 
        for (int i = 2 ; i <n+1 ; i++)
        {
            for(int j = 1 ; j < i ; j++)
            {
                if (nums[j-1] < nums[i-1])
                {
                    dp[i] = max(dp[i] , dp[j]+1) ; 
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); ;
    }
};
