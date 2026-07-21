class Solution {
public:


    int MOD = 1000000007 ; 

    // vector <int> bin_expo
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int r = n-1 ;

        sort(nums.begin() , nums.end()) ; 
        int l = 0 ; 

        vector <int> pow2(n , 1) ; 
        for (int i = 1 ; i < n ; i++)
        {
            pow2[i] = pow2[i-1]*2 % MOD ; 
        }


        int tot = 0 ;
        while(l <= r)
        {
            int s = nums[l] + nums[r] ; 
            if (s > target)
            {
                r-- ; 
            }
            else
            {
                tot = (tot + pow2[r - l]) % MOD ;
                l++ ; 
            }
        }
        return tot ; 
    }
};