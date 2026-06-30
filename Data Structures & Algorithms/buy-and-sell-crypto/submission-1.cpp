class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int buy = 0 ;
        int sell = 1 ; 
        
        int mp = 0 ; 
        for(sell ; sell < n ; sell++)
        {
            if (prices[buy] <= prices[sell])
            {
                mp = max(mp , prices[sell] - prices[buy]); 
            }
            else
            {
                while(buy < sell && prices[buy] > prices[sell])
                {
                    buy++ ; 
                } 
            }
        }
        return mp ; 
    }
};
