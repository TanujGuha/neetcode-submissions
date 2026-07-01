class Solution {
public:

    int helper(vector <int> &nums , int k)
    {
        int v = 0 ; 
        unordered_map <int,int> mpp ;
        int l = 0 ; 
        for (int r = 0 ; r < nums.size() ; r++)
        {
            mpp[nums[r]]++ ; 

            while(mpp.size() > k)
            {
                mpp[nums[l]]-- ; 
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]) ; 
                }
                l++ ; 
            }

            v += r-l+1 ; 
            
        }

        return v ; 
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums , k-1) ; 
    }
};