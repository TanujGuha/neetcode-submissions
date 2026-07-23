class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size() ; 
        vector <int> dp(n) ; 
        dp[0] = nums[0] ;

        int mxp = nums[0] ; 
        int mnp = nums[0] ; 

        for(int i = 1 ; i < n ; i++)
        {
            dp[i] = max({mxp*nums[i] , mnp*nums[i] , nums[i]}) ; 
            int temp1 = dp[i] ; 
            int temp2 = min({mxp*nums[i] , mnp*nums[i] , nums[i]}) ; 

            mxp = max(temp1 ,temp2) ; 
            mnp = min(temp1 , temp2) ; 
        } 

        return *max_element(dp.begin() , dp.end()) ; 


    }
};
