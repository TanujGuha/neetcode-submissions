class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ; 


        int ms = nums[0] ;
        int sum = nums[0] ;  

        for(int i = 1 ; i < n ; i++)
        {
            if (sum >= 0)
            {
                sum += nums[i] ; 
            }
            else 
            {
                sum = nums[i] ; 
            }

            ms = max(ms , sum) ; 
        }


        return ms ; 
    }
};
