class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        int l = 0 ; 
        int r = n-1;

        vector <pair<int,int>> vp(n) ; 
        for (int i = 0 ; i < n ; i++)
        {
            vp[i].first = nums[i] ; 
            vp[i].second = i ; 
        }
        sort(vp.begin() , vp.end()) ; 

        vector <int> ans ; 
        while(l < r)
        {

            int left = vp[l].first ; 
            int right = vp[r].first ; 
            if(left + right == target)
            {
                ans.push_back(vp[l].second) ; 
                ans.push_back(vp[r].second) ; 
                sort(ans.begin() , ans.end()) ; 
                return ans ; 
            }
            else if (left + right > target)
            {
                r-- ; 
            }
            else if (left + right < target)
            {
                l++ ; 
            }
        } 

        if(!ans.empty()) sort(ans.begin() , ans.end()) ; 
        return ans ; 
    }
};
