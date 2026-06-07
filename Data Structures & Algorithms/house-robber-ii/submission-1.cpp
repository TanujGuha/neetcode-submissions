class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ; 


        if (n == 1)
        {
            return  nums[0] ; 
        }

        if (n == 2)
        {
            return max(nums[0] , nums[1]) ; 
        }

        vector <int> v ; 
        for (int i = 0 ; i < n-1 ; i++)
        {
            v.push_back(nums[i]) ;
        }
        vector <int> v1 ; 
        for (int i = 1 ; i < n ; i++)
        {
            v1.push_back(nums[i]) ;
        }    

        return max(d(v , n-1) , d(v1,  n-1)) ;     

    }


    int d(vector <int> &nums, int s)
    {
        vector <int> dp(s) ; 

        dp[s-1] = nums[s-1] ; 
        dp[s-2] = max(nums[s-1] , nums[s-2]) ; 


        for(int i = s-3 ; i >= 0 ; i--){
            dp[i] = max(dp[i+1] , nums[i] + dp[i+2]) ; 
        }


        return dp[0] ; 
    }
};