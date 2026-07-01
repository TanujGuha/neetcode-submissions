class Solution {
public:


    bool can_eat(vector<int>& piles, int h , long long k)
    {
        int req = 0 ; 
        for (int i = 0 ; i < piles.size() ; i++)
        {
            req += (piles[i] + k - 1) / k ; 
            if (req > h) return false ;  
        }
        return true ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // '''
        // if k is the optimal, than and x > k is also going to work, but k-1 would not
        // so is a binary kind of thing, and the binary search will
        // be on the values that k can take .... 

        // Now the Problem is to effciently know where ther or not given a k , 
        // I can finish the load in "h" hours.

        // '''

        long long k_min = 1LL ; 
        long long k_max = 1000000000 ; 

        while(k_min < k_max)
        {
            int k_mid = (k_min + k_max)/2 ;
            if (can_eat(piles, h , k_mid))
            {
                k_max = k_mid ; 
            }
            else
            {
                k_min = k_mid + 1; 
            }

        }

        return k_max ; 


    }
};
