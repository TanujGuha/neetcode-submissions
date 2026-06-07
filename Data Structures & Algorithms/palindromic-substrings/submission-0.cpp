class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.size() ; 
        vector <vector <bool>> dp(n , vector <bool> (n , false)) ;

        int cnt = n ; 

        for(int i = 0 ; i < n ; i++)
        {
            dp[i][i] = true ; 
        }

        for (int i = 0 ; i+1 < n ; i++)
        {
            if (s[i] == s[i+1])
            {
                dp[i][i+1] = true ; 
                cnt++ ; 
            }
        } 


        for (int l = 3 ; l <= n ; l++)
        {
            for (int i = 0 ; i + l - 1 < n ; i++)
            {
                int j = i+l-1 ; 
                if (s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true ; 
                    cnt++ ; 
                }                
            }
        }

        return cnt ; 

    }
};
