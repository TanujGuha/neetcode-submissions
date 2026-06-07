class Solution {
public:
    int numDecodings(string s) {
        int n = s.size() ; 
        vector <int> dp(n+1, 0) ; 
        

        dp[n] = 1 ; 

        for (int i = n-1 ; i >= 0 ; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0 ; 
                continue ; 
            }

            dp[i] = dp[i+1] ; 


            if (i+1 >= n) continue ; 
            int val = (s[i] - '0')*10 + (s[i+1] - '0') ; 
            if (val <= 26 && val >= 10)
            {
                dp[i] += dp[i+2] ; 
            }
        }


        return dp[0] ;
    }
};
