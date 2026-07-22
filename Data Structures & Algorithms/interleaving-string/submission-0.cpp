class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = (int)s1.size() ;
        int m = (int)s2.size() ;

        int sz = (int)s3.size() ; 

        if(n + m != sz) return false ; 

        vector <vector<bool>> dp(n+1,  vector<bool>(m+1 , false)) ; 
        // dp[i][j] = true if we can make s3[0 ... i+j-1]
        // using s2[0 ... j-1] + s1[0 ... i-1] 

        // base cases
        dp[0][0] = true ;

        for (int i = 1 ; i <= m ; i++)
        {
            dp[0][i] = dp[0][i-1] && (s3[i-1] == s2[i-1]) ; 
        } 
        for (int i = 1 ; i <= n ; i++)
        {
            dp[i][0] = dp[i-1][0] && (s3[i-1] == s1[i-1]) ; 
        }      

        for (int r = 1 ; r <= n ; r++)
        {
            for(int c = 1 ;  c <= m ; c++)
            {
                dp[r][c] = ((s2[c-1] == s3[r+c-1]) && dp[r][c-1]) || ((s1[r-1] == s3[r+c-1]) && dp[r-1][c] ); 
            }
        }   


        return dp[n][m] ; 
    }
};
