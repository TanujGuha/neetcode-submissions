class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int,int> freq ; 

        int n = nums.size() ; 
        for(int i = 0 ; i < n ; i++)
        {
            freq[nums[i]]++ ; 
        }

        vector <pair<int,int>> v ; 
        for(auto it : freq)
        {
            v.push_back({it.second , it.first}) ; 
        }

        sort(v.begin() , v.end()) ; 


        vector <int> ans ; 
        int l = v.size() - 1 ; 
        for(int i = 0 ; i < k ; i++ , l--)
        {
            ans.push_back(v[l].second) ; 
        }

        return ans ; 
    }
};
