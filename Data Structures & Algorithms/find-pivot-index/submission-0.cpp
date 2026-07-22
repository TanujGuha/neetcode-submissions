class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = (int) nums.size() ; 
        vector <int> pref(n) ; 
        pref[0] = nums[0] ;
        int tot = nums[0] ; 

        for(int i = 1 ; i < n ; i++)
        {
            tot += nums[i] ; 
            pref[i] = pref[i-1] + nums[i] ;
        }

        for (int i = 0 ; i < n ; i++)
        {
            if (i == 0){
                if (0 == tot-nums[0]) return 0 ; 
            }
            else if(i == n-1){
                if (0 == tot-nums[n-1]) return n-1 ; 
            }
            else {
                if (pref[i-1] == tot - pref[i]) return i ; 
            }
        }

        return -1;  


    }
};