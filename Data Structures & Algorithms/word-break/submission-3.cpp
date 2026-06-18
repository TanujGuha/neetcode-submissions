class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ; 
        unordered_set <string> wd (wordDict.begin() , wordDict.end()) ; 

        vector <bool> dp(n+1 , false) ; 
        dp[n]  = true ; 

        for (int i = n-1 ; i >= 0 ; i--)
        {
            for (int j = i+1 ; j <= n ; j++)
            {
                string sb = s.substr(i , j-i) ; 
                if (wd.count(sb) && dp[j])
                {
                    dp[i] = true ;
                    break ;  
                } 
                
            }
        }

        return dp[0] ;
    }
};
