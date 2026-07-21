class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "" ;

        int n = (int)chars.size() ; 
        
        char c = chars[0] ;
        int cnt = 1 ; 
        for (int i = 1 ; i < n ; i++)
        {
            if (chars[i] == c) cnt++ ; 
            else
            {

                if (cnt == 1) {
                    s += c ; 
                    c = chars[i] ; 
                    continue ; 
                }
                s += c ; 
                s += to_string(cnt) ; 
                cnt = 1 ; 
                // s = "" ; 
                c = chars[i] ; 


            }
        }

        s += c;
        if (cnt > 1)
            s += to_string(cnt);

        int k = (int)s.size() ; 
        for (int i = 0 ; i < k ; i++)
        {
            chars[i] = s[i] ; 
        }

        return k ; 
        
    }
};