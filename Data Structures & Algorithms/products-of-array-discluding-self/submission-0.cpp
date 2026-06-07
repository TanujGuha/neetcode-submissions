class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        long long int p = 1 ; 
        int n = nums.size() ; 
        int c1 = 0 ; 
        for(auto i : nums)
        {
            p = p*i ; 
            if (i == 0)
            {
                c1++ ; 
            }
        }
        vector <int> ans ; 
        if (c1 == 1)
        {

            int pp = 1 ; 
            for (int i = 0  ; i < n ; i++)
            {
                if (nums[i] != 0)
                {
                    pp = pp * nums[i] ;
                }
            }


            for(int i = 0; i < n ; i++)
            {
                if (nums[i] == 0)
                {
                    ans.push_back(pp) ; 
                }
                else
                {
                    ans.push_back(0) ; 
                }
            }


            return ans ; 
        }
        
        if (c1 > 1)
        {
            for (int i = 0 ; i < n ; i++)
            {
                ans.push_back(0) ; 
            }

            return  ans ; 
        }


        for(int i = 0 ; i < n ; i++)
        {
            ans.push_back(p / nums[i]) ; 
        }

        return ans ; 
    }
};
