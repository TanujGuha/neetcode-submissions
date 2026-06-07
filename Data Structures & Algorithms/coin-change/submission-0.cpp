class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector <int> dp(amount+1 , amount+1) ; 
        sort(coins.begin() , coins.end()) ; 
        dp[0] = 0 ; 
        for (int i = 0 ; i < n ; i++)
        {
            if (coins[i] <= amount)
                dp[coins[i]] = 1 ;
            else 
                break ; 
        } 


        for (int i = 1 ; i <= amount ; i++)
        {

            int mm = amount + 1 ; 
            for (int j = 0 ; j < n ; j++)
            {
                if (i - coins[j] >= 0)
                {
                    mm = min(dp[i - coins[j]] + 1 , mm) ;
                }
                else
                {
                    break ; 
                }
            }
            dp[i] = mm ; 
        }


        if(dp[amount] > amount) 
        {
            return -1 ; 
        }
        return dp[amount] ;     
    }
};
