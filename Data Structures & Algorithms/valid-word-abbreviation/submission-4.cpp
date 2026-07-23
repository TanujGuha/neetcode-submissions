class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        int n = (int)word.size() ; 
        int m = (int)abbr.size() ; 

        int l = 0 ; 
        int r = 0 ;

        while(l < n && r < m)
        {
            int num = 0 ;
            while(isdigit(abbr[r]))
            {
                if (abbr[r] - '0' == 0 && num == 0) return false ; 
                num = num*10 + abbr[r] - '0' ;
                r++ ; 
            }
            while(num--)
            {
                l++ ; 
            }
            if (l >= n && r < m ||  l < n && r >= m || word[l] != abbr[r]) return false ; 
            else {
                l++ ; 
                r++ ; 

            }
        }
        return true ; 
    }
};