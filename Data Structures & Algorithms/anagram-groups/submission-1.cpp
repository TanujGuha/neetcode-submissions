class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string , vector<string>> mpp ; 

        for (string s :  strs)
        {
            string c = s ; 
            sort(c.begin() , c.end()) ; 
            mpp[c].push_back(s) ; 
        }

        vector <vector<string>> v ; 

        for (auto it : mpp)
        {
            vector <string> temp ; 
            for(auto i : it.second)
            {
                temp.push_back(i) ;
            }

            v.push_back(temp) ;
        }

        return v ; 
    }
};
