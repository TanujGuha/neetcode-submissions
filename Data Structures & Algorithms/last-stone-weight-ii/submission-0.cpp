class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin() , stones.end() , 0) ; 
        vector <bool> dp(total+1 , false) ;
        dp[0] = true ; 

        for (int i : stones)
        {
            for (int s = total ; s >= i ; s--)
            {
                dp[s] = dp[s]|| dp[s - i] ; 
            }
        } 

        int m = INT_MAX ;
        for(int i = 0 ; i< total+1 ; i++)
        {
            if (dp[i]) 
            {
                m = min(m , abs(total - 2*i)) ; 
            }
        }

        return m ; 
    }
};