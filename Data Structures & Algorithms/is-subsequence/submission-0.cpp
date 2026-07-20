class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0 ; 
        int r = 0 ; 

        int n1 = (int)s.size() ; 
        int n2 = (int)t.size() ; 

        while(l < n1 && r < n2)
        {
            if (s[l] == t[r])
            {
                l++ ; 
                r++ ; 
            }
            else r++ ;
        }

        if (l >= n1) return true ; 
        else return false ; 
    }
};