class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 ; 
        int r = nums.size()-1 ;


        while(l <= r)
        {
            int m = (l+r)/2; 
            int mid = m ; 

            if (nums[m] == target) return m ; 

            if (nums[l] <= nums[mid])  // left is completely sorted 
            {
                if (target > nums[mid] || target < nums[l])
                {
                    l = mid + 1 ; 
                }
                else r = mid - 1 ; 
            }
            else
            {
                if (target < nums[mid] || target > nums[r])
                {
                    r = mid - 1 ; 
                }
                else
                {
                    l = mid + 1 ; 
                }
            }
        }

        return -1 ; 
    }
};
