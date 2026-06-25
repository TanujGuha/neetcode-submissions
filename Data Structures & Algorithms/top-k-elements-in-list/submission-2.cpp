class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans ; 
        map <int,int> mpp ; 
        for(int i : nums)
        {
            mpp[i]++ ; 
        }
        set <pair<int,int>> temp ; 
        for (auto i : mpp)
        {
            temp.insert({-i.second , i.first}) ; 
        }
        int c = 0 ; 
        for (auto it = temp.begin() ; c < k && it!= temp.end() ; it++ , c++)
        {
            ans.push_back((*it).second) ; 
        }

        return ans ; 
    }
};
