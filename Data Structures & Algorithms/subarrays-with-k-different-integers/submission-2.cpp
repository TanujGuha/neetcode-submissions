class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res = 0 ; 
        int l = 0 ; 
        unordered_map <int,int> mpp ; 
        int cnt = 0 ;
        for (int r = 0 ; r < nums.size() ; r++)
        {
            mpp[nums[r]]++ ; 
            if (mpp[nums[r]] == 1)
            {
                k-- ;    // found a unique
            }

            if (k < 0) //  time to move ahead
            {
                mpp[nums[l]]-- ; 
                l++ ; 
                k++ ;
                cnt = 0 ; 
            }

            
            if (k == 0)
            {
                // mpp[nums[l]]-- ; 
                while(mpp[nums[l]] > 1)
                {
                    mpp[nums[l]]-- ; 
                    cnt++ ; 
                    l++ ; 
                }
                res += cnt + 1 ; 
            }

            
        }

        return res ; 
    }
};