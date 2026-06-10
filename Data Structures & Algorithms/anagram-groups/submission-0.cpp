class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size() ;
        map < multiset<char> , vector< string>>  mpp ; 

        for (int i = 0 ; i < n ; i++)
        {
            multiset <char> s ;
            for(auto j : strs[i])
            {
                s.insert(j) ; 
            }

            mpp[s].push_back(strs[i]) ; 
        }


        vector <vector <string>> ans ; 
        for (auto it : mpp)
        {
            ans.push_back(it.second) ; 
        }

        return ans ; 
    }
};
