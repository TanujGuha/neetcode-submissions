class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int)nums.size() ; 
        vector <int> pref(n) ;
        vector <int> suff(n) ; 

        pref[0] = nums[0] ; 
        suff[n-1] = nums[n-1] ; 



        for (int i = 1 ; i < n ; i++)
        {
            if (pref[i-1] == 0)
            {
                pref[i] = nums[i] ;
                continue ;
            } 
            pref[i] = pref[i-1]*nums[i] ; 
        }

        for(int i = n-2 ; i >= 0 ; i--)
        {
            if (suff[i+1] == 0)
            {
                suff[i] = nums[i] ; 
                continue ; 
            }
            suff[i] = suff[i+1]*nums[i] ;
        }

        return max(*max_element(pref.begin() , pref.end()) , *max_element(suff.begin() , suff.end())) ; 
    }
};
