class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = (int)nums.size() ; 

        int ls = 1 ; 
        int l = 1 ; 

        int lm = 1 ; 
        int l2 = 1 ; 
        for (int i = 1 ; i < n ; i++)
        {
            
            if (nums[i] > nums[i-1])
            {
                l++ ; 
            }
            else{
                l = 1 ; 
            }
            ls = max(ls , l) ;  

            if (nums[i] < nums[i-1]){
                l2++ ; 
            } 
            else {
                l2 = 1 ; 
            }
            lm = max(lm , l2) ; 
        }

        return max(ls , lm) ; 
    }
};