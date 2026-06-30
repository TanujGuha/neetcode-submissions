class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map <char , int> mpp ; 
        

        for(char i : s1) mpp[i]++ ; 
        int uni = mpp.size() ; 

        int nn = s1.size() ; 
        int n = s2.size() ; 
        for (int i = 0 ;i + nn <= n ; i++)
        {
            unordered_map <char ,int> temp ; 
            bool flag = true ; 
            int here = 0 ; 
            for (int j = 0 ; j < nn ; j++)
            {
                temp[s2[i+j]]++ ; 
                if (temp[s2[i+j]] > mpp[s2[i+j]]){
                    flag = false; 
                    break ; 
                }
                else if(temp[s2[i+j]] == mpp[s2[i+j]])
                {
                    here++ ; 
                }
            }
            if (flag && here == uni) return true ;
        }

        return false ; 
    }
};
