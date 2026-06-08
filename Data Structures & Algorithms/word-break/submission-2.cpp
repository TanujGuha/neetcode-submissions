class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        int n = s.size() ;  
        int l = wd.size() ; 

        vector <bool> dp(n+1) ; 
        dp[n] = true ; 


        for (int i = n-1 ; i >= 0 ; i--)
        {
            for (int j = 0 ; j < l ; j++)
            {
                int ll = wd[j].size() ; 
                if (i + ll <= n)
                {
                    if (dp[i+ll] == true && s.substr(i , ll) == wd[j])
                    {
                        dp[i] = true ; 
                    }
                }
            }
        }


        return dp[0] ;
    }
};
