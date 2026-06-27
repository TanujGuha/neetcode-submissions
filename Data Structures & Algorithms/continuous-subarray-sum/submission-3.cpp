class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp; 
        mpp[0] = -1 ; 

        int prev = 0 ; 
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            prev += nums[i] ; 
            if (mpp.count(prev%k))
            {
                if (i - mpp[prev%k] >= 2) return true ; 
            }
            else
            {
                if (prev%k == 0 && i > 0) return true ; 
                else if (prev%k != 0) mpp[prev%k] = i ; 
            }

        
        }

        return false ; 
    }
};