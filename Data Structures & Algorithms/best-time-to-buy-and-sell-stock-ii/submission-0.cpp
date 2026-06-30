class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;
        int buy = 0 ; 
        int sell = 1 ; 

        int profit = 0 ; 
        for(sell;  sell < n ; sell++)
        {
            if (prices[sell] > prices[buy])
            {
                profit += prices[sell] - prices[buy] ; 
                
            }
            buy = sell ; 
        }

        return profit ; 
    }
};