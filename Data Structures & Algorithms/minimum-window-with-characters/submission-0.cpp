class Solution {
public:
    string minWindow(string s, string t) {
        vector <int> target(128 , 0) ; 
        int unique = 0 ;
        for (char c : t){
            if (target[c] == 0)
            {
                unique++ ; 
            }
            target[c]++ ; 
        }


        
        int l = 0 ; 
        int start = -1 ;
        int ml = INT_MAX ; 

        vector<int> wind(128 , 0) ; 

        int mat = 0 ; 
        for(int r = 0  ; r < s.size() ; r++)
        {
            wind[s[r]]++ ; 
            if (wind[s[r]] == target[s[r]]) mat++ ; 


            while(mat == unique) // moving l ahead
            {
                char c = s[l] ; 
                if (target[c] > 0 && wind[c] == target[c]){
                    if (ml >  r - l + 1)
                    {
                        start = l ;
                        ml = r - l + 1 ; 
                    }
                    break ; 
                    
                }// cant delete this element here
                l++ ; 
                wind[c]-- ;
            }
        } 

        return start == -1 ? "" : s.substr(start , ml) ; 
    }
};
