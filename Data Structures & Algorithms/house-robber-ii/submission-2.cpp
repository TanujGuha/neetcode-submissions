class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 

        if (n == 1)
        {
            return nums[n-1] ;
        }
        if (n == 2)
        {
            return max(nums[0] , nums[1]) ; 
        }

        int st = 0 ;
        int edi = n-2 ; 


        vector <int> dp(n) ; 

        dp[edi] = nums[edi] ; 
        dp[edi-1] = max(nums[edi] ,nums[edi-1]) ; 

        for (int j = edi-2 ; j >= st ; j--){
            dp[j] = max(nums[j] + dp[j+2] , dp[j+1]) ; 
        }

        int v1 = dp[st] ; 

        st = 1 ; 
        edi = n-1 ; 
        dp[edi] = nums[edi] ; 
        dp[edi-1] = max(nums[edi-1] , nums[edi]) ; 

        for (int j = edi-2 ; j >= st ; j--)
        {
            dp[j] = max(dp[j+1] , dp[j+2] + nums[j]) ; 
        }

        return max(v1 , dp[st]) ; 
       
    }
};
