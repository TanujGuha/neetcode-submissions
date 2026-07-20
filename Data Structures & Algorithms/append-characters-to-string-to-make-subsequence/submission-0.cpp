class Solution {
public:
    int appendCharacters(string s, string t) {
        int l = 0 ; 
        int r = 0 ; 

        int n1 = (int)s.size() ; 
        int n2 = (int)t.size() ;

        while(l < n1 && r < n2)
        {
            if (s[l] == t[r]) {
                l++; 
                r++ ;
            }
            else l++ ; 
        }

        if (r < n2 && l >= n1)
        {
            return n2  - r ; 
        }
        return  0 ;
    }
};