class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp ; 
        mpp[0] = 1 ;
        int cnt = 0 ; 
        int pre = 0 ; 

        for(int x : nums)
        {
            pre += x ; 
            if (mpp.count(pre -k))
            {
                cnt += mpp[pre-k] ;
            }
            mpp[pre]++ ; 
        }

        return cnt ;
    }
};