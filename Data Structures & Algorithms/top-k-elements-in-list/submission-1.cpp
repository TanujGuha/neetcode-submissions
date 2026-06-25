class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans ; 
        map <int,int> mpp ; 
        for(int i : nums)
        {
            mpp[i]++ ; 
        }
        vector <pair<int,int>> temp ; 
        for (auto i : mpp)
        {
            temp.push_back({-i.second , i.first}) ; 
        }
        sort(temp.begin() , temp.end()) ; 
        for (int i = 0 ; i < k ; i++)
        {
            ans.push_back(temp[i].second) ; 
        }

        return ans ; 
    }
};
