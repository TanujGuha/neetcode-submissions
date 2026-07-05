class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector <int> last(26 , 0 ) ; 
        for (int i = 0 ; i < s.size() ; i++)
        {
            last[s[i] - 'a'] = i ;
        }

        int st = 0 ; 
        int end = 0 ;
        

        vector <int> ans ; 

        for (int i = 0 ; i < s.size() ; i++)
        {
            end = max(end , last[s[i] - 'a']) ; 
            if (end == i){
                ans.push_back(end - st + 1) ;
                
                st = i+1 ; 
            }
        }

        return ans ; 
    }
};
