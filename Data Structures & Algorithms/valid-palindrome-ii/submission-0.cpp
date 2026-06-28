class Solution {
public:


    bool ispalin(int st , int end , string s)
    {
        while(st < end)
        {
            if(s[st] != s[end]) return false ; 
            st++ ; 
            end-- ; 
        }
        return true ; 
    }
    bool validPalindrome(string s) {
        int n = s.size() ; 
        int l = 0 ; 
        int r = n-1 ; 

        while(l < r)
        {
            if (s[l] != s[r])
            {
                return ispalin(l+1 , r ,s) || ispalin(l , r-1 ,s) ;
            }
            l++ ; 
            r-- ;
        }
        return true ; 
        
    }
};