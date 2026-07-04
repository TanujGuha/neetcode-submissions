class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = nums[0] ; 
        int mx = nums[0] ;

        int n = nums.size() ; 

        for (int i = 1 ; i < n ; i++)
        {
            if (s < 0)
            {
                s = nums[i] ; 
            }
            else
            {
                s += nums[i] ; 
            }

            mx = max(mx , s) ; 
        }

        return mx ;
    }
};
