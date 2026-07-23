class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = (int)word1.size() ; 
        int n2 = (int)word2.size() ;

        string s = "" ; 

        bool c = true ; 
        int l = 0 , r = 0 ; 
        while(l < n1 && r < n2)
        {
            if (c)
            {
                s += word1[l]; 
                l++ ; 
                c = false ; 
            }
            else
            {
                s += word2[r] ;
                r++; 
                c = true ; 
            }
        }

        while(l < n1)
        {
            s += word1[l] ;
            l++ ; 
        }

        while(r < n2)
        {
            s += word2[r] ; 
            r++ ; 
        }


        return s ; 
    }
};