class Solution {
public:
    int maxDifference(string s) {
        vector <int> alpha(26 , -1) ; 
        for (char c : s)
        {
            int id = c - 'a' ; 
            if (alpha[id] == -1)
            {
                alpha[id] = 1 ;
            }
            else {
                alpha[id]++ ; 
            }
        }

        int max_odd  = 0; 
        int min_ev  = 1000000 ; 

        for (int i = 0 ; i < 26 ; i++)
        {
            if (alpha[i] == -1) continue ;
            else {
                if (alpha[i]%2) max_odd = max(max_odd , alpha[i]) ; 
                else min_ev = min(min_ev, alpha[i]) ; 
            }
        }

        return max_odd - min_ev ; 

    }
};