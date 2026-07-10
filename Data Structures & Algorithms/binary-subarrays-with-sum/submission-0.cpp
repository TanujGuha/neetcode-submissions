class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size() ; 
        unordered_map<int,int> mpp ;  
        mpp[0] = 1 ; 
        int curr = 0 ; 
        int res = 0 ; 


        for(int i = 0 ; i < n ; i++)
        {
            curr += nums[i] ;
             
            if (curr >= goal && mpp.count(curr - goal))
            {
                res += mpp[curr-goal] ; 
                // mpp[curr]++ ; 
            }

            mpp[curr]++ ;
        }

        return res ; 
    }
};