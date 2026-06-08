class Solution {
public:
    int maxProduct(vector<int>& nums) {

            int n = nums.size() ;
            int pdt_max = nums[0] ; 
            int pdt_min = nums[0] ; 

            vector <int> dp(n) ; 
            int ans = nums[0] ; 
            for(int i = 1 ; i < n ; i++)
            {
                int x = nums[i] ; 
                int prev_M = pdt_max ; 
                int prev_m = pdt_min ; 


                pdt_max = max({x , prev_M*x , prev_m*x}) ; 
                pdt_min = min({x , prev_M*x , prev_m*x}) ; 


                ans = max(ans , pdt_max) ; 
            }


            return ans ; 
    }
};
