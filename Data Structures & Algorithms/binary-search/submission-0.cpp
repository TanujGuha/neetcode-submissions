class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 ; 
        int r = nums.size()-1 ; 

        while(l <= r)
        {
            if (l == r && nums[l] != target) return -1 ;
            int m = (l+r)/2 ;
            if (nums[m] < target)
            {
                l = m+1 ; 
            }  
            else if (nums[m] > target)
            {
                r = m-1 ; 
            }
            else return m ;
        }
        return -1 ; 
    }
};
