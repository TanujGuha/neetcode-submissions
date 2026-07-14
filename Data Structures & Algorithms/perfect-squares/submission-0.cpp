class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1, INT_MAX) ; 

        dp[0] = 0 ; 

        for (int tar = 1 ; tar <= n ; tar++)
        {

            long long root = std::round(std::sqrt(tar)) ; 
            if (root*root == tar){
                dp[tar] = 1 ;
                continue ; 
            }

            for (int j = 1 ; j <= tar ; j++)
            {
                long long root = std::round(std::sqrt(j));
                if (root*root != j) continue ;

                dp[tar] = min(dp[tar - j] + 1 , dp[tar]) ;
            }
        }

        if (dp[n] == INT_MAX) 
        {
            return 0 ; 
        }
        else return dp[n] ;
    }
};