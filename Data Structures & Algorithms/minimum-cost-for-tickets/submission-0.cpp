class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        unordered_set<int> repo(days.begin(), days.end()) ; 
        vector <int> dp(366) ; 
        dp[0] = 0 ; 
        for(int i = 1 ; i <= 365 ; i++)
        {
            if(repo.count(i) > 0)
            {
                dp[i] = min({dp[i-1] + cost[0] , dp[max(0 , i - 7)] + cost[1], dp[max(0 , i-30)] + cost[2]}) ; 
            }
            else
            {
                dp[i] = dp[i-1] ;
            }
        }

        return dp[365] ; 
    }
};