class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26 , 0) ; 
        for(char  ch : s1) 
        {
            f1[ch -'a']++ ; 
        }
        int n = s2.size() ;


        for (int i = 0 ; i + s1.size() <= n ; i++)
        {
            vector<int> f2(26 , 0) ;
            for(int j = 0 ; j < s1.size() ; j++)
            {
                f2[s2[i+j] - 'a']++ ; 
            }

            if (f1 == f2) return true ; 
        }
        return false ;
    }
};
