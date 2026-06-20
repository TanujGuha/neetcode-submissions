class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        int max_pdt = nums[n-1] ;
        int min_pdt = nums[n-1] ; 
        int ans = nums[n-1] ; 
        vector <int> dp(n) ;

        for (int i = n-2 ; i >= 0 ; i--)
        {
            int nemx = max({nums[i] , max_pdt*nums[i] , min_pdt*nums[i]}) ; 
            int nemn = min({nums[i] , max_pdt*nums[i] , min_pdt*nums[i]}) ;


            max_pdt = max(nemx , nemn) ;
            min_pdt = min(nemn , nemx) ;

            ans = max(ans , max_pdt) ;
        }


        return ans ; 
    }
};
