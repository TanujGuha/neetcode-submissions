class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = (int)nums.size() ; 
        int mx = nums[0] ;
        int l = 1 ;
        int s = nums[0] ;  
        for (int i = 1 ; i < n ; i++)
        {
            if (nums[i] > nums[i-1]){
                s += nums[i] ; 
            }
            else {
                s = nums[i ] ;
            }

            mx = max(mx , s) ; 
        }

        return mx ;
    }
};