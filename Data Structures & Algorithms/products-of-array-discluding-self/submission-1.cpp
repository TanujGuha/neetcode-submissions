class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pdt = 1 ;
        int n = nums.size() ;
        set <int> idx ; 

        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] == 0) idx.insert(i) ; 
            else pdt = pdt* nums[i] ; 
        }

        if (idx.size()>1)
        {
            vector <int> ans(n , 0 );
            return ans ;   
        }
        else
        {
            vector<int> ans(n) ; 
            for (int i = 0 ; i < n ; i++)
            {
                if (idx.count(i) > 0) ans[i] = pdt ; 
                else if (idx.empty()) ans[i] = pdt / nums[i] ; 
                else ans[i] = 0 ;
            }

            return ans ; 
        }
    }
};
