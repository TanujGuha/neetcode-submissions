class Solution {
public:

    string encode(vector<string>& strs) {

        string s = "" ;
        
        for(int i = 0 ; i < strs.size() ; i++)
        {
            s += to_string(strs[i].size()) + "|" + strs[i] ; 

        }
        return s ; 

    }

    vector<string> decode(string s) {

        vector <string> ans ;
        int i = 0 ;  
        while(i < s.size()) 
        {


            int j = i + 1 ; 

            while(s[j] != '|') j++ ;

            int sl = stoi(s.substr(i , j - i)) ; 
            j++ ; 
            

            string ss  ;

            ss = s.substr(j , sl) ; 
            ans.push_back(ss) ; 


            i = j + sl ; 
            continue ;
        
            
        }

        return ans ; 
    }
};
