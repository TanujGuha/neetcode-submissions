class Solution {
public:
    int numRescueBoats(vector<int>& peoples, int limit) {
        sort(peoples.begin() , peoples.end()) ; 
        int n = peoples.size() ;
        int l = 0 ;
        int r = n-1 ; 


        int boats = 0 ;
        while(l <= r)
        {
            if ( l == r)
            {
                boats++ ; 
                break ;
            }
            if (peoples[r] >= limit)
            {
                boats++  ;
                r-- ; 
            }
            else
            {
                if (peoples[l] + peoples[r] <= limit)
                {
                    boats++ ; 
                    l++ ; 
                    r-- ;
                }
                else
                {
                    boats++ ; 
                    r-- ; 
                }
            }
        }
        return boats ; 
        
    }
};