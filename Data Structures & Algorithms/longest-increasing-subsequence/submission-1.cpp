class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ; 

        vector <int> dp(n , 1) ; 



        int ans = 1 ; 
        for(int j = 1 ; j < n ; j++)
        {
            for (int i = 0 ; i < j ; i++)
            {
                if (nums[j] > nums[i])
                {
                    dp[j] = max(1 + dp[i] , dp[j]) ; 
                }
            }

            ans = max(ans , dp[j]) ; 
        }


        return ans ; 
    }
};
