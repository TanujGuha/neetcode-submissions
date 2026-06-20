class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin() , nums.end(), 0) ; 
        if (sum & 1) return false ; 
        int target = sum/2 ; 
        int n = nums.size() ; 
        vector <int> dp(+target+1 , false) ; 
        dp[0] = true ; 

        for (auto num : nums)
        {
            for (int s = target ; s >= num ; s--)
            {
                dp[s] = dp[s] || dp[s-num] ; 
            }
        }

        return dp[target] ; 
    }
};
