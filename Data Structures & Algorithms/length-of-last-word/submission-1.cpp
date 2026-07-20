class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int st = s.size()-1 ; 

        while(st >= 0 && s[st] == ' ') st-- ;
        int r = st ; 
        while (st >= 0 && s[st] != ' ') st-- ; 
        return r - st ; 
    }
};