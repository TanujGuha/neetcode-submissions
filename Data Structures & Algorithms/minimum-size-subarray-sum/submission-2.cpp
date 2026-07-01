class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0 ; 
        int rs = 0 ; 
        int ans = INT_MAX ; 
        int ml = INT_MAX ; 
        for (int r = 0 ; r < nums.size() ; r++)
        {
            rs += nums[r] ;
            if(1)
            {
                while(rs >= target)
                {
                    ml = min(ml , r - l+1) ; 

                    rs -= nums[l] ; 
                    l++ ;

                } 
            }
            
        }
        return ml == INT_MAX ? 0 : ml ;  

        
    }
};